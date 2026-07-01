# MVVM 리팩토링 상세 계획

## 현재 아키텍처 문제 전체 목록

코드 전체를 읽은 결과 문제를 6개 카테고리로 분류합니다.

***

### 🔴 문제 1 — View가 Model을 직접 변이

`EventPanel::render()`는 `DeviceProfile*` raw pointer를 받아 필드를 직접 수정합니다.  하나의 함수에서 ImGui 렌더링 코드와 도메인 데이터 변이가 혼재합니다.

```cpp
// 현재 — EventPanel이 Model을 직접 쓰기
for (auto* t : targets) {
    if (isSrc) t->event.srcIpRandom = randomFlag;
}
```

`DevicePanel::render()` 역시 `p.enabled = !p.enabled`를 직접 변이합니다. 

***

### 🔴 문제 2 — `AppWindow::renderUI()`의 책임 과부하

[`AppWindow.cpp`의 `renderUI()`](https://github.com/creatorjun/LogGen/blob/main/src/ui/AppWindow.cpp)는 3가지 책임을 동시에 집니다. 

- **렌더링**: 3개 패널 레이아웃 및 크기 계산
- **엔진 생명주기**: `isRunning`, `wasRunning` 비교 후 `engine.start()` / `engine.stop()` 호출
- **프로파일 동기화**: `profilesDirty` 플래그로 엔진에 `updateProfile()` 전송

`static bool wasRunning`은 함수 재진입마다 상태를 추적하는 안티패턴입니다.

***

### 🟡 문제 3 — `UIState`가 ViewModel 역할을 하지 못함

[`UIState.h`](https://github.com/creatorjun/LogGen/blob/main/src/ui/UIState.h)는 단 2개 bool 필드만 가진 단순 struct입니다.  모든 패널이 이 상태를 **직접 읽고 씁니다.** `MonitorPanel`이 `state.isEngineRunning = true`를 직접 설정하는 구조는  상태의 소유권이 없는 View가 상태를 변이하는 패턴입니다.

***

### 🟡 문제 4 — `LogBuffer` / `ApiRequestBuffer`의 잘못된 위치

[`src/ui/LogBuffer.h`](https://github.com/creatorjun/LogGen/blob/main/src/ui/LogBuffer.h), [`LockFreeLogBuffer.h`](https://github.com/creatorjun/LogGen/blob/main/src/ui/LockFreeLogBuffer.h), [`ApiRequestBuffer.h`](https://github.com/creatorjun/LogGen/blob/main/src/ui/ApiRequestBuffer.h) 모두 `src/ui/`에 위치하지만  이들은 엔진 콜백에서 쓰이는 스레드 안전 채널입니다. Engine이 UI 디렉토리의 타입을 직접 참조하는 역방향 의존성이 발생합니다.

***

### 🟡 문제 5 — `TimeSeriesData`가 View에 혼재

[`MonitorPanel.h`의 `TimeSeriesData`](https://github.com/creatorjun/LogGen/blob/main/src/ui/MonitorPanel.h)는 ImGui에 전혀 의존하지 않는 순수 원형 버퍼 로직입니다.  View 파일에 선언되어 있어 테스트 및 재사용이 불가능합니다.

***

### 🟢 문제 6 — 색상 상수 파편화

`DevicePanel.cpp`, `EventPanel.cpp`, `MonitorPanel.cpp`, `AppWindow.cpp` 각각이 동일한 `ImVec4(0.941f, 0.941f, 0.941f, 1.0f)` 같은 리터럴을 독립적으로 선언합니다.  `UIConstants.h`에 색상 팔레트가 빠져 있습니다.

***

## 목표 아키텍처

```
┌──────────────────────────────────────────────────────────────┐
│  DOMAIN / INFRASTRUCTURE (기존 유지)                         │
│  src/core/  src/engine/  src/persistence/  src/infrastructure│
│  src/logging/                                                │
│  ↑ ImGui, UI에 대한 의존 없음 — 절대 변경 불가              │
└────────────────────────────┬─────────────────────────────────┘
                             │ reads
┌────────────────────────────▼─────────────────────────────────┐
│  CHANNEL  (신규: src/core/channel/)                          │
│  LogChannel.h   ApiChannel.h                                 │
│  엔진→UI 비동기 데이터 파이프, UI에 독립적                   │
└────────────────────────────┬─────────────────────────────────┘
                             │ exposes state
┌────────────────────────────▼─────────────────────────────────┐
│  VIEWMODEL  (신규: src/ui/viewmodel/)                        │
│  AppViewModel                                                │
│  DevicePanelViewModel                                        │
│  EventPanelViewModel                                         │
│  MonitorViewModel                                            │
│  SoarMockViewModel                                           │
│  상태 보유 + Command 처리 + 도메인 호출                       │
│  ImGui 의존 없음 → 단위 테스트 가능                          │
└────────────────────────────┬─────────────────────────────────┘
                             │ read-only ViewState + Commands
┌────────────────────────────▼─────────────────────────────────┐
│  VIEW  (기존 src/ui/ — 대폭 간소화)                          │
│  AppWindow  DevicePanel  EventPanel                          │
│  MonitorPanel  SoarMockPanel                                 │
│  ImGui 호출만 담당, 직접 Model 변이 없음                     │
└──────────────────────────────────────────────────────────────┘
```

***

## 최종 파일 구조

```
src/
├── core/
│   ├── DeviceProfile.h          (기존 유지)
│   ├── Constants.h              (기존 유지)
│   └── channel/                 ← 신규 디렉토리
│       ├── LogChannel.h         (LogBuffer.h + LockFreeLogBuffer.h 통합 이동)
│       └── ApiChannel.h         (ApiRequestBuffer.h 이동)
│
├── engine/                      (기존 유지)
├── infrastructure/              (기존 유지)
├── persistence/                 (기존 유지)
├── logging/                     (기존 유지)
│
├── ui/
│   ├── viewmodel/               ← 신규 핵심 레이어
│   │   ├── AppViewModel.h/.cpp
│   │   ├── DevicePanelViewModel.h/.cpp
│   │   ├── EventPanelViewModel.h/.cpp
│   │   ├── MonitorViewModel.h/.cpp
│   │   └── SoarMockViewModel.h/.cpp
│   │
│   ├── AppWindow.h/.cpp         (View만 — 레이아웃 + 패널 라우팅)
│   ├── DevicePanel.h/.cpp       (ImGui 렌더링만)
│   ├── EventPanel.h/.cpp        (ImGui 렌더링만)
│   ├── MonitorPanel.h/.cpp      (ImGui 렌더링만)
│   ├── SoarMockPanel.h/.cpp     (ImGui 렌더링만)
│   ├── UIConstants.h            (색상 팔레트 추가)
│   └── UIState.h                (삭제 → AppViewModel로 흡수)
│
└── main.cpp                     (AppViewModel 생성 후 AppWindow 주입)
```

***

## 단계별 리팩토링 계획

### Phase 1 — Channel 분리 (사이드이펙트 없음, 1일)

**목표**: UI 디렉토리에서 엔진 채널 타입을 꺼냅니다.

`src/ui/LogBuffer.h`, `LockFreeLogBuffer.h` → `src/core/channel/LogChannel.h`로 이동  
`src/ui/ApiRequestBuffer.h` → `src/core/channel/ApiChannel.h`로 이동

모든 `#include` 경로를 업데이트합니다. 로직 변경 없음.

***

### Phase 2 — UIConstants 색상 팔레트 완성 (30분)

`UIConstants.h`에 아래를 추가합니다.

```cpp
// UIConstants.h에 추가할 색상 팔레트 네임스페이스
namespace UIColor {
    inline constexpr ImVec4 kText        = {0.141f, 0.141f, 0.141f, 1.0f};
    inline constexpr ImVec4 kTextMuted   = {0.380f, 0.380f, 0.380f, 1.0f};
    inline constexpr ImVec4 kTextReadOnly= {0.380f, 0.380f, 0.380f, 1.0f};
    inline constexpr ImVec4 kAccent      = {0.000f, 0.471f, 0.831f, 1.0f};
    inline constexpr ImVec4 kAccentHover = {0.016f, 0.400f, 0.722f, 1.0f};
    inline constexpr ImVec4 kAccentActive= {0.004f, 0.329f, 0.604f, 1.0f};
    inline constexpr ImVec4 kAccentDim   = {0.000f, 0.471f, 0.831f, 0.18f};
    inline constexpr ImVec4 kInputBg     = {0.941f, 0.941f, 0.941f, 1.0f};
    inline constexpr ImVec4 kInputHover  = {0.922f, 0.922f, 0.922f, 1.0f};
    inline constexpr ImVec4 kInputActive = {0.878f, 0.878f, 0.878f, 1.0f};
    inline constexpr ImVec4 kSurface     = {1.000f, 1.000f, 1.000f, 1.0f};
    inline constexpr ImVec4 kBg          = {0.961f, 0.961f, 0.961f, 1.0f};
    inline constexpr ImVec4 kBorder      = {0.820f, 0.820f, 0.820f, 1.0f};
    inline constexpr ImVec4 kOrange      = {0.800f, 0.400f, 0.000f, 1.0f};
    inline constexpr ImVec4 kRed         = {0.820f, 0.110f, 0.110f, 1.0f};
    inline constexpr ImVec4 kRedHover    = {0.720f, 0.090f, 0.090f, 1.0f};
    inline constexpr ImVec4 kTextInverse = {1.000f, 1.000f, 1.000f, 1.0f};
}
```

각 패널의 로컬 `static const ImVec4 kColorXxx`를 `UIColor::kXxx`로 치환합니다.

***

### Phase 3 — `TimeSeriesData` 분리 (30분)

`MonitorPanel.h`에 선언된 `TimeSeriesData`를 `src/ui/viewmodel/TimeSeriesData.h`로 추출합니다. ImGui 의존 없음을 확인하고 그대로 이동합니다.

***

### Phase 4 — `AppViewModel` 추출 (핵심, 2일)

**현재 `AppWindow`에서 이관할 로직**:

| 현재 위치 | 이관 대상 |
|---|---|
| `static bool wasRunning` | `AppViewModel::m_wasRunning` 멤버 |
| `renderUI()` 내 엔진 start/stop 분기 | `AppViewModel::tickEngineState()` |
| `m_profilesDirty` 관리 | `AppViewModel::markDirty()` / `flushDirtyProfiles()` |
| `triggerReload()` / `pollReload()` | `AppViewModel::triggerReload()` / `pollReload()` |
| `m_uiState` | `AppViewModel`이 소유 |

```cpp
// src/ui/viewmodel/AppViewModel.h
class AppViewModel {
public:
    AppViewModel(std::unique_ptr<IGeneratorEngine> engine,
                 std::unique_ptr<ISoarMockEngine>  soarEngine,
                 LogChannel&                       logChannel,
                 ApiChannel&                       apiChannel);

    // 매 프레임 AppWindow가 호출
    void tick(std::vector<DeviceProfile>& profiles,
              const std::function<void()>& onSave);

    // View → ViewModel Commands
    void requestStart();
    void requestStop();
    void requestReload();
    void markProfilesDirty();

    // View가 읽는 상태
    bool isRunning()   const { return m_isRunning; }
    bool isReloading() const { return m_isReloading; }

    IGeneratorEngine& engine()     { return *m_engine; }
    ISoarMockEngine&  soarEngine() { return *m_soarEngine; }

private:
    void tickEngineState(std::vector<DeviceProfile>& profiles,
                         const std::function<void()>& onSave);
    void tickReload(std::vector<DeviceProfile>& profiles,
                    const std::function<void()>& onSave);

    std::unique_ptr<IGeneratorEngine>  m_engine;
    std::unique_ptr<ISoarMockEngine>   m_soarEngine;
    LogChannel&                        m_logChannel;
    ApiChannel&                        m_apiChannel;

    bool m_isRunning   = false;
    bool m_wasRunning  = false;   // 이전 프레임 상태 추적
    bool m_isReloading = false;
    bool m_isDirty     = false;

    std::future<std::vector<DeviceProfile>> m_reloadFuture;
};
```

`AppWindow::renderUI()`는 순수 렌더링만 남습니다:

```cpp
void AppWindow::renderUI(std::vector<DeviceProfile>& profiles,
                         const std::function<void()>& onSave) {
    m_viewModel.tick(profiles, onSave);   // 상태 전이 위임

    // 레이아웃 계산 + 패널 라우팅만
    m_devicePanel.render(profiles, m_devicePanelVm, width, m_fontBold);
    m_eventPanel.render(m_eventPanelVm, colW, m_fontBold);
    m_monitorPanel.render(m_monitorVm, rightW, m_fontBold);
}
```

***

### Phase 5 — `EventPanelViewModel` 추출 (핵심, 2일)

View의 직접 변이를 Command 패턴으로 전환합니다.

```cpp
// src/ui/viewmodel/EventPanelViewModel.h
class EventPanelViewModel {
public:
    explicit EventPanelViewModel(std::vector<DeviceProfile>& profiles,
                                  std::function<void()>       onDirty);

    struct ViewState {
        bool        isMultiEdit    = false;
        int         selectionCount = 0;
        std::string deviceName;    // read-only 표시용
        std::string eqpIp;
        std::string collectorIp;
        uint16_t    port           = 514;
        bool        useTCP         = false;
        bool        srcIpRandom    = false;
        std::string srcIp;
        std::string srcIpStart;
        std::string srcIpEnd;
        bool        dstIpRandom    = false;
        std::string dstIpFixed;
        std::string dstIpStart;
        std::string dstIpEnd;
        float       normalRate     = 100.0f;
        bool        burstEnable    = false;
        float       burstRate      = 1000.0f;
        float       burstDurationSec  = 5.0f;
        float       burstIntervalSec  = 30.0f;
    };

    // 매 프레임 호출 — profiles로부터 ViewState 동기화
    void refresh();
    const ViewState& state() const { return m_state; }

    // Commands — View가 직접 profiles를 건드리는 대신 이것을 호출
    void setEqpIp(std::string_view v);
    void setCollectorIp(std::string_view v);
    void setPort(uint16_t v);
    void setProtocol(bool useTCP);
    void setSrcIpRandom(bool v);
    void setSrcIp(std::string_view v);
    void setSrcIpStart(std::string_view v);
    void setSrcIpEnd(std::string_view v);
    void setDstIpRandom(bool v);
    void setDstIpFixed(std::string_view v);
    void setDstIpStart(std::string_view v);
    void setDstIpEnd(std::string_view v);
    void setNormalRate(float v);
    void setBurstEnable(bool v);
    void setBurstRate(float v);
    void setBurstDurationSec(float v);
    void setBurstIntervalSec(float v);

private:
    std::vector<DeviceProfile>&  m_profiles;
    std::function<void()>        m_onDirty;
    ViewState                    m_state;
    std::vector<DeviceProfile*>  m_targets;  // enabled 장비 캐시
};
```

`EventPanel::render()`의 시그니처가 단순해집니다:

```cpp
// 변경 전
void EventPanel::render(std::vector<DeviceProfile>& profiles,
                        UIState& state, float width,
                        ImFont* fontBold,
                        const std::function<void()>& onDirty);

// 변경 후
void EventPanel::render(EventPanelViewModel& vm,
                        float width, ImFont* fontBold);
```

***

### Phase 6 — `DevicePanelViewModel` / `MonitorViewModel` 추출 (1일)

**`DevicePanelViewModel`**: `DevicePanel`에서 `p.enabled = !p.enabled` 변이 및 popup 상태를 ViewModel로 이동합니다. 팝업 데이터(`m_popupTitle`, `m_popupContent`, `m_copyBuf`)는 View 전용 렌더링 상태이므로 Panel에 유지하되, `enabled` 토글 Command는 ViewModel이 소유합니다.

**`MonitorViewModel`**: `m_terminalLines`, `m_terminalSelected`, `m_time`, `m_totalEpsData`, `m_deviceEpsData` 등 데이터 집계 로직을 ViewModel로 이동합니다. `MonitorPanel`은 ViewModel에서 읽어 ImPlot / 터미널 렌더링만 수행합니다.

***

### Phase 7 — `main.cpp` 수정 (30분)

```cpp
// 변경 후 main.cpp 구조
auto logChannel = std::make_shared<LogChannel>();
auto apiChannel = std::make_shared<ApiChannel>();

auto appVm = std::make_unique<AppViewModel>(
    std::move(genEngine),
    std::move(soarEngine),
    *logChannel, *apiChannel);

AppWindow app(width, height, title, std::move(appVm));
```

***

## Phase별 리스크 및 검증 포인트

| Phase | 작업 | 리스크 | 검증 방법 |
|---|---|---|---|
| 1 | Channel 이동 | include 경로 누락 | CMake 빌드 성공 |
| 2 | 색상 상수화 | `constexpr ImVec4` 초기화 순서 | 런타임 렌더링 동일성 |
| 3 | TimeSeriesData 이동 | 헤더 중복 include | 빌드 성공 |
| 4 | AppViewModel | `wasRunning` static 제거 후 엔진 전환 | start/stop 수동 반복 테스트 |
| 5 | EventPanelViewModel | 단일/다중 편집 분기 로직 | 각 필드 편집 후 프로파일 JSON 확인 |
| 6 | MonitorViewModel | EPS 차트 시계열 데이터 정확성 | 엔진 실행 중 그래프 확인 |
| 7 | main.cpp | 의존성 주입 순서 | 전체 통합 빌드 및 실행 |

***