// src/ui/AppWindow.cpp
#include "AppWindow.h"
#include "logging/Logger.h"
#include "ui/UIConstants.h"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <implot.h>
#include <GLFW/glfw3.h>
#include <thread>
#include <chrono>

#ifdef _WIN32
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>
#include <windows.h>
#endif

static void applyM365LightTheme() {
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding    = 8.0f;
    style.FrameRounding     = 4.0f;
    style.PopupRounding     = 6.0f;
    style.ScrollbarRounding = 4.0f;
    style.GrabRounding      = 3.0f;
    style.TabRounding       = 4.0f;
    style.ChildRounding     = 6.0f;
    style.WindowPadding     = ImVec2(0.0f,  0.0f);
    style.FramePadding      = ImVec2(10.0f, 6.0f);
    style.ItemSpacing       = ImVec2(8.0f,  6.0f);
    style.ItemInnerSpacing  = ImVec2(6.0f,  4.0f);
    style.IndentSpacing     = 16.0f;
    style.ScrollbarSize     = 8.0f;
    style.GrabMinSize       = 8.0f;
    style.WindowBorderSize  = 0.0f;
    style.FrameBorderSize   = 1.0f;
    style.ChildBorderSize   = 1.0f;
    style.PopupBorderSize   = 1.0f;

    ImVec4* c = style.Colors;
    const ImVec4 bg            = UIColors::kBg;
    const ImVec4 surface       = UIColors::kSurface;
    const ImVec4 surfaceRaised = UIColors::kSurfaceMid;
    const ImVec4 inputBg       = UIColors::kSurfaceSub;
    const ImVec4 inputHov      = UIColors::kFrameBgHovered;
    const ImVec4 border        = UIColors::kBorderNormal;
    const ImVec4 borderFocus   = UIColors::kAccent;
    const ImVec4 accent        = UIColors::kAccent;
    const ImVec4 accentHov     = UIColors::kAccentHover;
    const ImVec4 accentAct     = UIColors::kAccentActive;
    const ImVec4 text          = UIColors::kTextPrimary;
    const ImVec4 textDisabled  = UIColors::kTextDisabled;
    c[ImGuiCol_Text]                  = text;
    c[ImGuiCol_TextDisabled]          = textDisabled;
    c[ImGuiCol_WindowBg]              = bg;
    c[ImGuiCol_ChildBg]               = surface;
    c[ImGuiCol_PopupBg]               = surface;
    c[ImGuiCol_Border]                = border;
    c[ImGuiCol_FrameBg]               = inputBg;
    c[ImGuiCol_FrameBgHovered]        = inputHov;
    c[ImGuiCol_FrameBgActive]         = UIColors::kFrameBgActive;
    c[ImGuiCol_TitleBg]               = bg;
    c[ImGuiCol_TitleBgActive]         = bg;
    c[ImGuiCol_TitleBgCollapsed]      = bg;
    c[ImGuiCol_MenuBarBg]             = surface;
    c[ImGuiCol_ScrollbarBg]           = UIColors::kTransparent;
    c[ImGuiCol_ScrollbarGrab]         = UIColors::kScrollbarGrab;
    c[ImGuiCol_ScrollbarGrabHovered]  = UIColors::kScrollbarGrabHov;
    c[ImGuiCol_ScrollbarGrabActive]   = accent;
    c[ImGuiCol_CheckMark]             = accent;
    c[ImGuiCol_SliderGrab]            = accent;
    c[ImGuiCol_SliderGrabActive]      = accentAct;
    c[ImGuiCol_Button]                = inputBg;
    c[ImGuiCol_ButtonHovered]         = inputHov;
    c[ImGuiCol_ButtonActive]          = UIColors::kFrameBgActive;
    c[ImGuiCol_Header]                = UIColors::kAccentSelect;
    c[ImGuiCol_HeaderHovered]         = UIColors::kAccentSelectHov;
    c[ImGuiCol_HeaderActive]          = UIColors::kAccentSelectAct;
    c[ImGuiCol_Separator]             = border;
    c[ImGuiCol_SeparatorHovered]      = borderFocus;
    c[ImGuiCol_SeparatorActive]       = accentHov;
    c[ImGuiCol_ResizeGrip]            = UIColors::kTransparent;
    c[ImGuiCol_Tab]                   = surfaceRaised;
    c[ImGuiCol_TabHovered]            = inputHov;
    c[ImGuiCol_TabActive]             = surface;
    c[ImGuiCol_TabUnfocused]          = bg;
    c[ImGuiCol_TabUnfocusedActive]    = surfaceRaised;
    c[ImGuiCol_PlotLines]             = accent;
    c[ImGuiCol_PlotLinesHovered]      = accentHov;
    c[ImGuiCol_PlotHistogram]         = accent;
    c[ImGuiCol_PlotHistogramHovered]  = accentHov;
    c[ImGuiCol_TableHeaderBg]         = inputBg;
    c[ImGuiCol_TableBorderStrong]     = border;
    c[ImGuiCol_TableBorderLight]      = border;
    c[ImGuiCol_TextSelectedBg]        = UIColors::kAccentSelectAct;
    c[ImGuiCol_DragDropTarget]        = accent;
    c[ImGuiCol_NavHighlight]          = accent;
    c[ImGuiCol_NavWindowingHighlight] = accentHov;
    c[ImGuiCol_NavWindowingDimBg]     = UIColors::kModalDimBg;
    c[ImGuiCol_ModalWindowDimBg]      = UIColors::kModalDimBg;
}

static void loadWindowIcon(GLFWwindow* window) {
#ifdef _WIN32
    HWND hwnd = glfwGetWin32Window(window);
    HMODULE hModule = GetModuleHandle(NULL);
    HICON hIcon = LoadIcon(hModule, MAKEINTRESOURCE(1));
    if (hIcon) {
        SendMessage(hwnd, WM_SETICON, ICON_BIG,   reinterpret_cast<LPARAM>(hIcon));
        SendMessage(hwnd, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(hIcon));
    } else {
        LOG_WARN("UI", "Window icon resource not found (MAKEINTRESOURCE 1)");
    }
#else
    (void)window;
#endif
}

AppWindow::AppWindow(int width, int height, const std::string& title,
                     std::unique_ptr<IGeneratorEngine> engine,
                     std::unique_ptr<ISoarMockEngine>  soarEngine)
    : m_width(width)
    , m_height(height)
    , m_title(title)
    , m_viewModel(std::move(engine), std::move(soarEngine), m_logBuffer, m_apiBuffer)
{}

AppWindow::~AppWindow() {
    LOG_INFO("UI", "AppWindow destroying");
    ImPlot::DestroyContext();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    if (m_window) glfwDestroyWindow(m_window);
    glfwTerminate();
    LOG_INFO("UI", "AppWindow destroyed");
}

bool AppWindow::init() {
    LOG_INFO("UI", "Initializing GLFW and OpenGL context");
    if (!glfwInit()) {
        LOG_ERROR("UI", "glfwInit() failed");
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif
    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
    if (!m_window) {
        LOG_ERROR("UI", "glfwCreateWindow() failed: " + m_title);
        glfwTerminate();
        return false;
    }
    glfwSetWindowSizeLimits(m_window,
        UIConstants::kWindowMinWidth, UIConstants::kWindowMinHeight,
        GLFW_DONT_CARE, GLFW_DONT_CARE);
    loadWindowIcon(m_window);
    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(0);
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImPlot::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    applyM365LightTheme();
    ImGui_ImplGlfw_InitForOpenGL(m_window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    setupFonts();
    m_viewModel.soarEngine().setRequestCallback([this](const ApiRequestEntry& e) {
        m_apiBuffer.push(e);
    });
    LOG_INFO("UI", "AppWindow init complete. size="
             + std::to_string(m_width) + "x" + std::to_string(m_height));
    return true;
}

void AppWindow::setupFonts() {
    ImGuiIO& io = ImGui::GetIO();
    ImFontConfig cfg;
    cfg.OversampleH = 2;
    cfg.OversampleV = 2;
    const ImWchar* ranges = io.Fonts->GetGlyphRangesKorean();
    m_fontRegular = io.Fonts->AddFontFromFileTTF(
        "assets/fonts/NanumGothic.ttf", UIConstants::kFontSize, &cfg, ranges);
    if (!m_fontRegular)
        LOG_WARN("UI", "Regular font load failed: assets/fonts/NanumGothic.ttf");
    m_fontBold = io.Fonts->AddFontFromFileTTF(
        "assets/fonts/NanumGothicBold.ttf", UIConstants::kFontSize, &cfg, ranges);
    if (!m_fontBold) {
        LOG_WARN("UI", "Bold font load failed - fallback to regular");
        m_fontBold = m_fontRegular;
    }
    io.FontDefault = m_fontRegular;
    LOG_INFO("UI", "Fonts loaded");
}

void AppWindow::mainLoop(std::vector<DeviceProfile>& profiles,
                         std::function<void()> onSaveRequest) {
    using clock     = std::chrono::steady_clock;
    using ms_double = std::chrono::duration<double, std::milli>;

    m_profiles  = &profiles;
    m_monitorVM = std::make_unique<MonitorPanelViewModel>(
        m_viewModel.engine(), profiles, m_logBuffer, m_viewModel);
    m_deviceVM.reset(
        profiles,
        [this]() { return m_viewModel.isReloading(); },
        [this, &onSaveRequest]() { m_viewModel.markDirty(); onSaveRequest(); },
        [this]() { m_viewModel.requestReload(); });
    m_eventVM.reset(
        profiles,
        [this, &onSaveRequest]() { m_viewModel.markDirty(); onSaveRequest(); });

    LOG_INFO("UI", "Entering main render loop");
    while (!glfwWindowShouldClose(m_window)) {
        const auto frameStart = clock::now();
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        renderUI(profiles, onSaveRequest);
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(m_window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(UIColors::kBg.x, UIColors::kBg.y, UIColors::kBg.z, UIColors::kBg.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(m_window);
        const double elapsed   = ms_double(clock::now() - frameStart).count();
        const double remaining = UIConstants::kTargetFrameMs - elapsed;
        if (remaining > 0.5)
            std::this_thread::sleep_for(
                std::chrono::microseconds(
                    static_cast<long long>(remaining * 1000.0 - 400.0)));
    }
    LOG_INFO("UI", "Main render loop exited");
}

void AppWindow::renderUI(std::vector<DeviceProfile>& profiles,
                         const std::function<void()>& onSaveRequest) {
    m_viewModel.tick(profiles, onSaveRequest);

    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->Pos);
    ImGui::SetNextWindowSize(viewport->Size);

    constexpr ImGuiWindowFlags kRootFlags =
        ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize   | ImGuiWindowFlags_NoMove     |
        ImGuiWindowFlags_NoBringToFrontOnFocus;

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding,   0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding,    ImVec2(16.0f, 16.0f));
    ImGui::PushStyleColor(ImGuiCol_WindowBg, UIColors::kBg);
    ImGui::Begin("MainWorkspace", nullptr, kRootFlags);
    ImGui::PopStyleVar(3);
    ImGui::PopStyleColor();

    const float totalW = ImGui::GetContentRegionAvail().x;
    const float gap    = 12.0f;
    const float colW   = totalW * 0.22f;
    const float rightW = totalW - colW * 2.0f - gap * 2.0f;
    const float dt     = ImGui::GetIO().DeltaTime;

    m_monitorVM->tick(dt, m_viewModel.isRunning());
    const bool wantsStart = m_monitorVM->isRunning() && !m_viewModel.isRunning();
    const bool wantsStop  = !m_monitorVM->isRunning() && m_viewModel.isRunning();
    if (wantsStart) m_viewModel.requestStart();
    if (wantsStop)  m_viewModel.requestStop();

    m_devicePanel.render(m_deviceVM, colW, m_fontBold);
    ImGui::SameLine(0.0f, gap);
    m_eventPanel.render(m_eventVM, colW, m_fontBold);
    ImGui::SameLine(0.0f, gap);
    m_monitorPanel.render(*m_monitorVM, m_viewModel.soarEngine(), m_apiBuffer,
                          rightW, m_fontBold);

    ImGui::End();
}

void AppWindow::markProfilesDirty() {
    m_viewModel.markDirty();
}
