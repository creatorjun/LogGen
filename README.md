# SIM Log Generator

C++ 기반 SIM 연동 테스트용 로그 생성기. 복수의 가상 디바이스 프로파일을 정의하고 TCP/UDP로 로그를 전송하며, SOAR Mock REST API 서버를 내장합니다.

---

## 목차

- [개발 환경 요구사항](#개발-환경-요구사항)
- [빠른 시작 (원라이너)](#빠른-시작-원라이너)
  - [Oracle Linux 8.13](#oracle-linux-813)
  - [Windows](#windows)
  - [macOS](#macos)
- [개발 환경 세팅 (단계별)](#개발-환경-세팅-단계별)
  - [Windows](#windows-1)
  - [Oracle Linux 8.13](#oracle-linux-813-1)
  - [macOS](#macos-1)
- [빌드 방법](#빌드-방법)
  - [Windows — 완전 재빌드 (권장)](#windows--완전-재빌드-권장)
  - [Linux / macOS — 완전 재빌드](#linux--macos--완전-재빌드)
  - [증분 빌드](#증분-빌드)
- [실행 방법](#실행-방법)
- [UI 사용법](#ui-사용법)
  - [Device 패널](#device-패널)
  - [Event 패널](#event-패널)
  - [Monitor 패널](#monitor-패널)
- [로그 전송 방식](#로그-전송-방식)
- [SOAR Mock API 서버](#soar-mock-api-서버)
  - [리슨 포트 및 엔드포인트](#리슨-포트-및-엔드포인트)
  - [요청--응답-예시](#요청--응답-예시)
- [프로파일 설정 파일](#프로파일-설정-파일)
- [프로젝트 구조](#프로젝트-구조)

---

## 개발 환경 요구사항

| 항목 | 최소 버전 | 비고 |
|------|-----------|------|
| CMake | 3.20 이상 | |
| C++ 컴파일러 | C++17 지원 | MSVC 2019+, GCC 10+, Clang 12+ |
| vcpkg | 최신 | 패키지 관리자 |
| OpenGL | 3.3 Core | GPU 드라이버 포함 |

**vcpkg 의존 패키지**

```
imgui[glfw-binding,opengl3-binding,freetype]
implot
glfw3
yaml-cpp
fmt
nlohmann-json
cpp-httplib
```

---

## 빠른 시작 (원라이너)

### Oracle Linux 8.13

아래 명령어 한 줄로 패키지 설치 → vcpkg 설치 → 클론 → 빌드 → `/root`에 릴리즈 tar.gz 백업까지 완료됩니다.

```bash
sudo dnf update -y && \
sudo dnf config-manager --set-enabled ol8_codeready_builder && \
sudo dnf install -y gcc gcc-c++ make cmake git curl zip unzip tar \
  pkgconfig mesa-libGL-devel mesa-libGLU-devel \
  libX11-devel libXrandr-devel libXinerama-devel \
  libXcursor-devel libXi-devel freetype-devel && \
{ [ -d "$HOME/vcpkg" ] || git clone https://github.com/microsoft/vcpkg.git ~/vcpkg && ~/vcpkg/bootstrap-vcpkg.sh; } && \
{ [ -d "loggen" ] || git clone https://github.com/creatorjun/loggen.git; } && \
cd loggen && \
~/vcpkg/vcpkg install && \
rm -rf build && \
cmake -B build -S . \
  -DCMAKE_TOOLCHAIN_FILE="$HOME/vcpkg/scripts/buildsystems/vcpkg.cmake" \
  -DCMAKE_BUILD_TYPE=Release && \
cmake --build build -j$(nproc) && \
tar -czf /root/SIMLogGenerator_$(date +%Y%m%d_%H%M%S).tar.gz \
  -C build SIMLogGenerator \
  -C .. assets config templates ti_data 2>/dev/null || \
tar -czf /root/SIMLogGenerator_$(date +%Y%m%d_%H%M%S).tar.gz -C build SIMLogGenerator
```

> 빌드 성공 후 `/root/SIMLogGenerator_YYYYMMDD_HHMMSS.tar.gz` 파일이 생성됩니다.

---

### Windows

**PowerShell (관리자)** 에서 실행합니다. Visual Studio 2022 및 Git이 사전 설치되어 있어야 합니다.

```powershell
git clone https://github.com/microsoft/vcpkg.git C:\vcpkg; `
C:\vcpkg\bootstrap-vcpkg.bat; `
C:\vcpkg\vcpkg integrate install; `
C:\vcpkg\vcpkg install imgui[glfw-binding,opengl3-binding,freetype]:x64-windows implot:x64-windows glfw3:x64-windows nlohmann-json:x64-windows cpp-httplib:x64-windows yaml-cpp:x64-windows fmt:x64-windows; `
git clone https://github.com/creatorjun/loggen.git; `
cd loggen; `
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake"; `
cmake --build build --config Release
```

---

### macOS

Xcode Command Line Tools와 Homebrew가 사전 설치되어 있어야 합니다.

```bash
brew install cmake git && \
{ [ -d "$HOME/vcpkg" ] || git clone https://github.com/microsoft/vcpkg.git ~/vcpkg && ~/vcpkg/bootstrap-vcpkg.sh; } && \
{ [ -d "loggen" ] || git clone https://github.com/creatorjun/loggen.git; } && \
cd loggen && \
~/vcpkg/vcpkg install && \
rm -rf build && \
cmake -B build -S . \
  -DCMAKE_TOOLCHAIN_FILE="$HOME/vcpkg/scripts/buildsystems/vcpkg.cmake" \
  -DCMAKE_BUILD_TYPE=Release && \
cmake --build build -j$(sysctl -n hw.logicalcpu)
```

---

## 개발 환경 세팅 (단계별)

### Windows

#### 1. vcpkg 설치

```cmd
git clone https://github.com/microsoft/vcpkg.git C:\vcpkg
cd C:\vcpkg
bootstrap-vcpkg.bat
vcpkg integrate install
```

#### 2. 의존 패키지 설치

```cmd
vcpkg install imgui[glfw-binding,opengl3-binding,freetype]:x64-windows ^
              implot:x64-windows ^
              glfw3:x64-windows ^
              nlohmann-json:x64-windows ^
              yaml-cpp:x64-windows ^
              fmt:x64-windows ^
              cpp-httplib:x64-windows
```

#### 3. Visual Studio 설치

Visual Studio 2019 또는 2022에서 **C++를 사용한 데스크톱 개발** 워크로드를 선택해 설치합니다.

---

### Oracle Linux 8.13

#### 1. 시스템 패키지 설치

```bash
sudo dnf update -y
sudo dnf config-manager --set-enabled ol8_codeready_builder
sudo dnf install -y gcc gcc-c++ make cmake git curl zip unzip tar \
                   pkgconfig mesa-libGL-devel mesa-libGLU-devel \
                   libX11-devel libXrandr-devel libXinerama-devel \
                   libXcursor-devel libXi-devel freetype-devel
```

#### 2. vcpkg 설치

```bash
git clone https://github.com/microsoft/vcpkg.git ~/vcpkg
~/vcpkg/bootstrap-vcpkg.sh
```

#### 3. 의존 패키지 설치

```bash
~/vcpkg/vcpkg install imgui[glfw-binding,opengl3-binding,freetype] \
                      implot glfw3 nlohmann-json yaml-cpp fmt cpp-httplib
```

---

### macOS

#### 1. Xcode Command Line Tools 및 Homebrew 설치

```bash
xcode-select --install
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
brew install cmake git
```

#### 2. vcpkg 설치

```bash
git clone https://github.com/microsoft/vcpkg.git ~/vcpkg
~/vcpkg/bootstrap-vcpkg.sh
```

#### 3. 의존 패키지 설치

```bash
~/vcpkg/vcpkg install imgui[glfw-binding,opengl3-binding,freetype] \
                      implot glfw3 nlohmann-json yaml-cpp fmt cpp-httplib
```

---

## 빌드 방법

### Windows — 완전 재빌드 (권장)

기존 빌드 캐시를 완전히 삭제하고 처음부터 다시 빌드합니다.

```cmd
rd /s /q build && cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake" && cmake --build build --config Release && .\build\Release\SIMLogGenerator.exe
```

> vcpkg 경로가 다른 경우 `C:/vcpkg` 부분을 실제 경로로 변경합니다.

Visual Studio 버전을 명시하려면 `-G` 옵션을 추가합니다.

```cmd
rem Visual Studio 2022
cmake -B build -S . -G "Visual Studio 17 2022" -A x64 ^
      -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake"

rem Visual Studio 2019
cmake -B build -S . -G "Visual Studio 16 2019" -A x64 ^
      -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake"
```

---

### Linux / macOS — 완전 재빌드

```bash
rm -rf build && cmake -B build -S . \
  -DCMAKE_TOOLCHAIN_FILE="$HOME/vcpkg/scripts/buildsystems/vcpkg.cmake" \
  -DCMAKE_BUILD_TYPE=Release && \
cmake --build build -j$(nproc) && \
./build/SIMLogGenerator
```

macOS에서 `nproc` 대신 `$(sysctl -n hw.logicalcpu)` 를 사용합니다.

```bash
rm -rf build && cmake -B build -S . \
  -DCMAKE_TOOLCHAIN_FILE="$HOME/vcpkg/scripts/buildsystems/vcpkg.cmake" \
  -DCMAKE_BUILD_TYPE=Release && \
cmake --build build -j$(sysctl -n hw.logicalcpu) && \
./build/SIMLogGenerator
```

---

### 증분 빌드

소스 파일만 수정한 경우 빌드 폴더를 삭제하지 않고 빌드합니다.

**Windows**
```cmd
cmake --build build --config Release
```

**Linux / macOS**
```bash
cmake --build build -j$(nproc)
```

---

## 실행 방법

빌드 완료 후 실행 파일은 아래 경로에 생성됩니다.

| OS | 경로 |
|----|------|
| Windows | `build\Release\SIMLogGenerator.exe` |
| Linux / macOS | `build/SIMLogGenerator` |

실행 시 `assets/fonts/` 디렉터리의 폰트 파일(NanumGothic.ttf, NanumGothicBold.ttf)이 필요합니다. 프로젝트 루트에서 실행합니다.

---

## UI 사용법

애플리케이션은 세 개의 패널로 구성됩니다.

### Device 패널

좌측 패널. 로그를 생성할 가상 디바이스를 관리합니다.

- **활성화 토글** — 장비 카드를 클릭하면 `enabled` 상태가 토글됩니다. 활성화된 장비는 파란색으로 표시되며, START 시 해당 장비만 로그를 생성합니다.
- **프로파일 편집** — 카드를 클릭하면 선택 상태가 되어 Event 패널에서 해당 장비의 설정을 편집할 수 있습니다.
  - **Device Name** — 로그에 표시되는 디바이스 식별자
  - **Collector IP / Port** — 로그를 수신할 대상 서버의 IP와 포트
  - **Protocol** — TCP 또는 UDP 선택
  - **EPS (Events Per Second)** — 초당 로그 전송 횟수
  - **Log Type** — 전송할 로그 포맷 선택

### Event 패널

가운데 패널. 각 디바이스별 공격 시나리오 이벤트를 설정합니다.

- 선택된 디바이스에 적용할 시나리오 유형을 지정합니다.
- 시나리오가 활성화되면 해당 유형의 공격 로그가 EPS에 맞춰 삽입됩니다.

### Monitor 패널

우측 패널. 실시간 로그 전송 현황을 모니터링합니다.

#### Log 탭

- **터미널 영역** — 전송된 로그를 실시간으로 표시합니다. 새 로그 수신 시 자동 스크롤됩니다.
  - `Ctrl+A` : 전체 선택
  - 우클릭 컨텍스트 메뉴 : Copy, Copy All, Select All
- **Total Sent** — 세션 누적 전송 로그 수
- **EPS 차트** — 최근 120초간 초당 전송량(EPS) 추이를 실시간 그래프로 표시
- **START / STOP 버튼** — 로그 전송 엔진 시작 및 중지

#### SOAR 탭

내장 SOAR Mock API 서버의 수신 요청 목록을 표시합니다.

---

## 로그 전송 방식

각 디바이스 프로파일에서 설정한 프로토콜에 따라 로그를 전송합니다.

| 항목 | 내용 |
|------|------|
| 프로토콜 | TCP 또는 UDP (디바이스별 독립 설정) |
| 전송 단위 | 로그 1건 = 1 메시지 |
| 연결 관리 | TCP는 세션 유지, 연결 실패 시 재연결 시도 |
| 전송률 제어 | EPS 값 기반 토큰 버킷 방식으로 전송 간격 조절 |
| 스레드 구조 | 디바이스별 독립 워커 스레드, 공유 스레드 풀 사용 |

---

## SOAR Mock API 서버

SOAR 연동 테스트를 위한 HTTP REST API 서버를 내장합니다. 애플리케이션 실행과 함께 자동으로 시작됩니다.

### 리슨 포트 및 엔드포인트

| 항목 | 값 |
|------|----|  
| 기본 리슨 포트 | `8080` |
| 바인드 주소 | `0.0.0.0` (모든 인터페이스) |
| 프로토콜 | HTTP/1.1 |

| 메서드 | 엔드포인트 | 설명 |
|--------|------------|------|
| `POST` | `/api/alert` | SOAR 경보 수신 |
| `POST` | `/api/incident` | 인시던트 생성 수신 |
| `GET` | `/api/status` | 서버 상태 확인 |

### 요청 / 응답 예시

#### POST `/api/alert`

**요청**
```json
{
  "device": "Firewall-01",
  "severity": "HIGH",
  "message": "Port scan detected from 192.168.1.100",
  "timestamp": "2026-06-19T13:00:00Z"
}
```

**응답** `200 OK`
```json
{
  "status": "received",
  "id": "alert-20260619-001"
}
```

#### GET `/api/status`

**응답** `200 OK`
```json
{
  "status": "running",
  "received_count": 42
}
```

> 포트를 변경하려면 `src/engine/SoarMockEngine.cpp` 내 리슨 포트 상수를 수정 후 재빌드합니다.

---

## 프로파일 설정 파일

디바이스 프로파일은 JSON 형식으로 자동 저장 및 로드됩니다.

| 항목 | 내용 |
|------|------|
| 저장 경로 | 실행 파일과 동일한 디렉터리의 `config/last_session.json` |
| 저장 시점 | START 버튼 클릭 및 프로그램 종료 시 자동 저장 |
| 로드 시점 | 애플리케이션 시작 시 자동 로드 |

**`last_session.json` 구조 예시**
```json
[
  {
    "id": "device-001",
    "name": "Firewall-01",
    "enabled": true,
    "collector": {
      "ip": "127.0.0.1",
      "port": 514
    },
    "protocol": "TCP",
    "eps": 10,
    "logType": "CEF"
  }
]
```

---

## 프로젝트 구조

```
SIMLogGenerator/
├── assets/
│   └── fonts/               # NanumGothic.ttf, NanumGothicBold.ttf
├── src/
│   ├── core/                # 도메인 모델 (DeviceProfile, LogEntry 등)
│   ├── engine/              # 로그 생성 엔진, SOAR Mock 엔진 (인터페이스 + 구현)
│   ├── infrastructure/      # TCP/UDP Sender, Receiver 구현체
│   ├── persistence/         # 프로파일 JSON 직렬화/역직렬화
│   └── ui/                  # ImGui 기반 패널 (AppWindow, MonitorPanel 등)
├── CMakeLists.txt
└── README.md
```
