import asyncio

TARGET_PORTS = [80, 433, 514, 601, 8080, 9000, 9040]
count = 0
last_count = 0


def inc(n=1):
    global count
    count += n


async def status_reporter():
    global count, last_count
    while True:
        await asyncio.sleep(1)
        eps = count - last_count
        print(f"[상태] 총 수신량: {count} / 초당 처리량(EPS): {eps}")
        last_count = count


class UDPReceiver(asyncio.DatagramProtocol):
    def __init__(self, port):
        self.port = port

    def datagram_received(self, data, addr):
        inc()
        try:
            text = data.decode("utf-8", errors="replace").strip()
        except Exception:
            text = repr(data)
        print(f"[UDP:{self.port}] from {addr[0]}:{addr[1]} | {text}")

    def error_received(self, exc):
        pass


async def handle_tcp(reader, writer, port):
    peer = writer.get_extra_info("peername")
    addr_str = f"{peer[0]}:{peer[1]}" if peer else "unknown"
    try:
        buf = b""
        while True:
            chunk = await reader.read(65536)
            if not chunk:
                break
            buf += chunk
            lines = buf.split(b"\n")
            buf = lines[-1]
            for line in lines[:-1]:
                inc()
                try:
                    text = line.decode("utf-8", errors="replace").strip()
                except Exception:
                    text = repr(line)
                print(f"[TCP:{port}] from {addr_str} | {text}")
    except (ConnectionResetError, asyncio.IncompleteReadError):
        pass
    finally:
        if buf:
            inc(1)
            try:
                text = buf.decode("utf-8", errors="replace").strip()
            except Exception:
                text = repr(buf)
            if text:
                print(f"[TCP:{port}] from {addr_str} | {text}")
        writer.close()
        try:
            await writer.wait_closed()
        except Exception:
            pass


async def main():
    loop = asyncio.get_running_loop()
    bound = []

    asyncio.create_task(status_reporter())

    for port in TARGET_PORTS:
        try:
            await loop.create_datagram_endpoint(
                lambda p=port: UDPReceiver(p),
                local_addr=("0.0.0.0", port)
            )
            bound.append(f"UDP:{port}")
        except OSError:
            pass

        try:
            server = await asyncio.start_server(
                lambda r, w, p=port: handle_tcp(r, w, p),
                "0.0.0.0", port
            )
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