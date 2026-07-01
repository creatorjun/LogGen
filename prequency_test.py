import asyncio
import time

TARGET_PORTS = [80, 433, 514, 601, 8080, 9000, 9040]
count = 0
last_count = 0

# 화면 출력을 제거하고 순수하게 카운트만 증가시킵니다.
def inc(n=1):
    global count
    count += n

# 1초마다 초당 수신량(EPS)과 총 수신량을 출력하는 백그라운드 태스크
async def status_reporter():
    global count, last_count
    while True:
        await asyncio.sleep(1)
        eps = count - last_count
        print(f"[상태] 총 수신량: {count} / 초당 처리량(EPS): {eps}")
        last_count = count

class UDPReceiver(asyncio.DatagramProtocol):
    def datagram_received(self, data, addr):
        inc()

    def error_received(self, exc):
        pass

async def handle_tcp(reader, writer):
    try:
        buf = b""
        while True:
            chunk = await reader.read(65536)
            if not chunk:
                break
            buf += chunk
            lines = buf.split(b"\n")
            buf = lines[-1]
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

async def main():
    loop = asyncio.get_running_loop()
    bound = []

    # 상태 출력 태스크 실행
    asyncio.create_task(status_reporter())

    for port in TARGET_PORTS:
        try:
            # UDP 소켓 수신 버퍼를 늘리고 싶다면 아래처럼 커스텀 소켓을 사용할 수도 있습니다.
            # (기본값으로도 print만 제거하면 성능이 비약적으로 상승합니다.)
            await loop.create_datagram_endpoint(
                UDPReceiver, local_addr=("0.0.0.0", port)
            )
            bound.append(f"UDP:{port}")
        except OSError:
            pass

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
        print(f"\n[종료] 총 수신: {count}")