import asyncio
import socket
import time

TARGET_PORTS = [80, 433, 514, 601, 8080, 9000, 9040]

# SO_RCVBUF 크기: 64MB — 고속 UDP 수신 시 커널 버퍼 드롭 방지
UDP_RECV_BUF = 64 * 1024 * 1024

# asyncio 단일 스레드 이벤트 루프 내에서만 접근하므로 Lock 불필요
count     = 0
last_count = 0

def inc(n: int = 1) -> None:
    global count
    count += n

async def status_reporter() -> None:
    global last_count
    while True:
        await asyncio.sleep(1)
        eps        = count - last_count
        last_count = count
        print(f"[상태] 총 수신량: {count:,} / EPS: {eps:,}")

class UDPReceiver(asyncio.DatagramProtocol):
    """단일 포트 UDP 수신 프로토콜."""
    def datagram_received(self, data: bytes, addr) -> None:
        inc()

    def error_received(self, exc: Exception) -> None:
        pass

async def handle_tcp(reader: asyncio.StreamReader,
                     writer: asyncio.StreamWriter) -> None:
    """TCP 스트림 수신 — 개행(\n) 구분자로 로그 1건 카운트."""
    try:
        buf = b""
        while True:
            chunk = await reader.read(65536)
            if not chunk:
                break
            buf  += chunk
            lines = buf.split(b"\n")
            buf   = lines[-1]
            if len(lines) > 1:
                inc(len(lines) - 1)
    except (ConnectionResetError, asyncio.IncompleteReadError):
        pass
    finally:
        if buf:
            inc(1)
        writer.close()
        try:
            await writer.wait_closed()
        except Exception:
            pass

def _make_udp_socket(port: int) -> socket.socket:
    """SO_RCVBUF를 확장한 UDP 소켓 생성."""
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    try:
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF, UDP_RECV_BUF)
    except OSError:
        pass  # 권한 부족 시 기본값 유지
    sock.bind(("0.0.0.0", port))
    sock.setblocking(False)
    return sock

async def main() -> None:
    loop  = asyncio.get_running_loop()
    bound = []

    asyncio.create_task(status_reporter())

    for port in TARGET_PORTS:
        # UDP — 커스텀 소켓으로 수신 버퍼 확장
        try:
            sock = _make_udp_socket(port)
            await loop.create_datagram_endpoint(UDPReceiver, sock=sock)
            actual_buf = sock.getsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF)
            bound.append(f"UDP:{port}(buf={actual_buf//1024}KB)")
        except OSError:
            pass

        # TCP
        try:
            server = await asyncio.start_server(handle_tcp, "0.0.0.0", port)
            asyncio.create_task(server.serve_forever())
            bound.append(f"TCP:{port}")
        except OSError:
            pass

    if not bound:
        print("[오류] 바인딩에 성공한 포트가 없습니다.")
        return

    print(f"[*] 대기 중: {bound}")
    await asyncio.Event().wait()

if __name__ == "__main__":
    try:
        asyncio.run(main())
    except KeyboardInterrupt:
        print(f"\n[종료] 총 수신: {count:,}")
