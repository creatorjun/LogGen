// src/ui/UIConstants.h
#pragma once

#include <imgui.h>

namespace UIConstants {

    inline constexpr int    kWindowWidth     = 1280;
    inline constexpr int    kWindowHeight    = 720;
    inline constexpr int    kWindowMinWidth  = 800;
    inline constexpr int    kWindowMinHeight = 540;
    inline constexpr double kTargetFps       = 144.0;
    inline constexpr double kTargetFrameMs   = 1000.0 / kTargetFps;
    inline constexpr float  kFontSize        = 16.0f;

} // namespace UIConstants

namespace UIColors {

    // --- Text ---
    inline constexpr ImVec4 kTextPrimary     = ImVec4(0.141f, 0.141f, 0.141f, 1.0f);
    inline constexpr ImVec4 kTextMuted       = ImVec4(0.380f, 0.380f, 0.380f, 1.0f);
    inline constexpr ImVec4 kTextOnAccent    = ImVec4(1.000f, 1.000f, 1.000f, 1.0f);
    inline constexpr ImVec4 kTextGreen       = ImVec4(0.059f, 0.439f, 0.184f, 1.0f);
    inline constexpr ImVec4 kTextDisabled    = ImVec4(0.600f, 0.600f, 0.600f, 1.0f);

    // --- Accent (Blue) ---
    inline constexpr ImVec4 kAccent          = ImVec4(0.000f, 0.471f, 0.831f, 1.0f);
    inline constexpr ImVec4 kAccentHover     = ImVec4(0.016f, 0.400f, 0.722f, 1.0f);
    inline constexpr ImVec4 kAccentActive    = ImVec4(0.004f, 0.329f, 0.604f, 1.0f);
    inline constexpr ImVec4 kAccentDim       = ImVec4(0.000f, 0.471f, 0.831f, 0.18f);
    inline constexpr ImVec4 kAccentDimHover  = ImVec4(0.000f, 0.471f, 0.831f, 0.28f);
    inline constexpr ImVec4 kAccentSubtle    = ImVec4(0.016f, 0.400f, 0.722f, 0.20f);
    inline constexpr ImVec4 kAccentSelect    = ImVec4(0.000f, 0.471f, 0.831f, 0.15f);
    inline constexpr ImVec4 kAccentSelectHov = ImVec4(0.000f, 0.471f, 0.831f, 0.10f);
    inline constexpr ImVec4 kAccentSelectAct = ImVec4(0.000f, 0.471f, 0.831f, 0.25f);

    // --- Danger (Red) ---
    inline constexpr ImVec4 kDanger          = ImVec4(0.820f, 0.110f, 0.110f, 1.0f);
    inline constexpr ImVec4 kDangerHover     = ImVec4(0.720f, 0.090f, 0.090f, 1.0f);
    inline constexpr ImVec4 kDangerActive    = ImVec4(0.640f, 0.070f, 0.070f, 1.0f);

    // --- Warning (Orange) ---
    inline constexpr ImVec4 kOrange          = ImVec4(0.800f, 0.400f, 0.000f, 1.0f);

    // --- Surface ---
    inline constexpr ImVec4 kBg              = ImVec4(0.961f, 0.961f, 0.961f, 1.0f);
    inline constexpr ImVec4 kSurface         = ImVec4(1.000f, 1.000f, 1.000f, 1.0f);
    inline constexpr ImVec4 kSurfaceMid      = ImVec4(0.961f, 0.961f, 0.961f, 1.0f);
    inline constexpr ImVec4 kSurfaceSub      = ImVec4(0.941f, 0.941f, 0.941f, 1.0f);
    inline constexpr ImVec4 kSurfaceSubAlpha = ImVec4(0.941f, 0.941f, 0.941f, 0.55f);
    inline constexpr ImVec4 kTransparent     = ImVec4(0.000f, 0.000f, 0.000f, 0.0f);

    // --- Card ---
    inline constexpr ImVec4 kCardNormal      = ImVec4(0.941f, 0.941f, 0.941f, 0.55f);
    inline constexpr ImVec4 kCardHover       = ImVec4(0.900f, 0.900f, 0.900f, 0.70f);
    inline constexpr ImVec4 kCardBorderOff   = ImVec4(0.820f, 0.820f, 0.820f, 0.60f);

    // --- Border ---
    inline constexpr ImVec4 kBorderNormal    = ImVec4(0.820f, 0.820f, 0.820f, 1.0f);

    // --- Modal ---
    inline constexpr ImVec4 kModalDimBg      = ImVec4(0.000f, 0.000f, 0.000f, 0.25f);

    // --- Frame (Input) ---
    inline constexpr ImVec4 kFrameBg         = ImVec4(0.953f, 0.953f, 0.953f, 1.0f);
    inline constexpr ImVec4 kFrameBgHovered  = ImVec4(0.941f, 0.941f, 0.941f, 1.0f);
    inline constexpr ImVec4 kFrameBgActive   = ImVec4(0.878f, 0.878f, 0.878f, 1.0f);
    inline constexpr ImVec4 kFrameBorder     = ImVec4(0.800f, 0.800f, 0.800f, 1.0f);

    // --- Scrollbar ---
    inline constexpr ImVec4 kScrollbarGrab   = ImVec4(0.780f, 0.780f, 0.780f, 1.0f);
    inline constexpr ImVec4 kScrollbarGrabHov= ImVec4(0.650f, 0.650f, 0.650f, 1.0f);

    // --- Small Button ---
    inline constexpr ImVec4 kSmallBtnOffNorm = ImVec4(0.800f, 0.800f, 0.800f, 0.50f);
    inline constexpr ImVec4 kSmallBtnOffHov  = ImVec4(0.750f, 0.750f, 0.750f, 0.80f);
    inline constexpr ImVec4 kSmallBtnOffAct  = ImVec4(0.700f, 0.700f, 0.700f, 1.00f);
    inline constexpr ImVec4 kSmallBtnOffBdr  = ImVec4(0.650f, 0.650f, 0.650f, 0.70f);

    // --- Secondary Button ---
    inline constexpr ImVec4 kSecondaryBtn       = ImVec4(0.941f, 0.941f, 0.941f, 1.0f);
    inline constexpr ImVec4 kSecondaryBtnHover  = ImVec4(0.878f, 0.878f, 0.878f, 1.0f);
    inline constexpr ImVec4 kSecondaryBtnActive = ImVec4(0.820f, 0.820f, 0.820f, 1.0f);

} // namespace UIColors

namespace UIText {

    constexpr const char* APP_TITLE                  = "Log Generator";
    constexpr const char* APP_DESCRIPTION            = "For EyeCloudXoar";

    constexpr const char* DEVICE_PANEL_SECTION       = "\ub514\ubc14\uc774\uc2a4";
    constexpr const char* DEVICE_RELOAD_TOOLTIP      = "\ud15c\ud50c\ub9bf \ub9ac\ub85c\ub4dc";
    constexpr const char* DEVICE_RELOADING_LABEL     = "\ub85c\ub529 \uc911...";
    constexpr const char* DEVICE_PROFILE_SECTION     = "\ud504\ub85c\ud30c\uc77c \ud3b8\uc9d1";
    constexpr const char* DEVICE_NAME_LABEL          = "\uc7a5\ube44\uba85";
    constexpr const char* DEVICE_IP_LABEL            = "\ubc1c\uc2e0 IP";
    constexpr const char* COLLECTOR_IP_LABEL         = "\uc218\uc2e0 IP";
    constexpr const char* PORT_LABEL                 = "\ud3ec\ud2b8";
    constexpr const char* PROTOCOL_LABEL             = "\ud504\ub85c\ud1a0\ucf5c";
    constexpr const char* PROTOCOL_UDP               = "UDP";
    constexpr const char* PROTOCOL_TCP               = "TCP";
    constexpr const char* BASE_EPS_LABEL             = "\uae30\ubcf8 EPS";

    constexpr const char* EVENT_PANEL_SECTION        = "\uc774\ubca4\ud2b8 \uc2dc\ubbac\ub808\uc774\uc158";
    constexpr const char* EVENT_TARGET_DEVICE_LABEL  = "\ub300\uc0c1 \ub514\ubc14\uc774\uc2a4";
    constexpr const char* EVENT_NO_DEVICE            = "\ub4f1\ub85d\ub41c \ub514\ubc14\uc774\uc2a4\uac00 \uc5c6\uc2b5\ub2c8\ub2e4";
    constexpr const char* EVENT_SELECT_DEVICE        = "\ub514\ubc14\uc774\uc2a4\ub97c \uc120\ud0dd\ud574 \uc8fc\uc138\uc694";
    constexpr const char* EVENT_DEVICE_COMBO_HINT    = "\uc120\ud0dd...";
    constexpr const char* SCHEDULER_SECTION          = "\uc2a4\ucf00\uc904\ub7ec \uc124\uc815";
    constexpr const char* BURST_ENABLE_LABEL         = "\ubc84\uc2a4\ud2b8 \ubc1c\uc0dd";
    constexpr const char* BURST_EPS_LABEL            = "\ubc84\uc2a4\ud2b8 EPS";
    constexpr const char* BURST_DURATION_LABEL       = "\ubc84\uc2a4\ud2b8 \uc9c0\uc18d \uc2dc\uac04 (s)";
    constexpr const char* BURST_INTERVAL_LABEL       = "\ubc84\uc2a4\ud2b8 \uc8fc\uae30 (s)";
    constexpr const char* CURRENT_EPS_FMT            = "\ud604\uc7ac EPS: %.1f";
    constexpr const char* EVENT_CONFIG_SECTION       = "\uc774\ubca4\ud2b8 \uc124\uc815";
    constexpr const char* SRC_IP_LABEL               = "\ucd9c\ubc1c\uc9c0 IP";
    constexpr const char* SRC_IP_RANDOM_LABEL        = "\ucd9c\ubc1c\uc9c0 IP \ub79c\ub364";
    constexpr const char* SRC_IP_START_LABEL         = "\ucd9c\ubc1c\uc9c0 IP \uc2dc\uc791";
    constexpr const char* SRC_IP_END_LABEL           = "\ucd9c\ubc1c\uc9c0 IP \ub05d";
    constexpr const char* DST_IP_LABEL               = "\ubaa9\uc801\uc9c0 IP";
    constexpr const char* DST_IP_RANDOM_LABEL        = "\ubaa9\uc801\uc9c0 IP \ub79c\ub364";
    constexpr const char* DST_IP_START_LABEL         = "\ubaa9\uc801\uc9c0 IP \uc2dc\uc791";
    constexpr const char* DST_IP_END_LABEL           = "\ubaa9\uc801\uc9c0 IP \ub05d";

    constexpr const char* MONITOR_PANEL_SECTION      = "\ub77c\uc774\ube0c \ud130\ubbf8\ub110";
    constexpr const char* STATS_TOTAL_SENT_LABEL     = "\uc804\uc1a1 \uc644\ub8cc";
    constexpr const char* CHART_TOTAL_EPS_LINE       = "\uc644 EPS";
    constexpr const char* CHART_X_AXIS_LABEL         = "\uacbd\uacfc \uc2dc\uac04 (s)";
    constexpr const char* CHART_Y_AXIS_LABEL         = "EPS";
    constexpr const char* BTN_START                  = "\uc2dc\uc791";
    constexpr const char* BTN_STOP                   = "\uc77c\uc2dc\uc815\uc9c0";

    constexpr const char* LOG_DATE_OFFSET_LABEL      = "\ub85c\uadf8 \uc0dd\uc131\uc77c";
    constexpr const char* LOG_DATE_OFFSET_UNIT       = "\uc77c";
    constexpr const char* LOG_DATE_OFFSET_TOOLTIP    = "\ub85c\uadf8 \ud0c0\uc784\uc2a4\ud0ec\uc744 \uc624\ub298 \uae30\uc900\uc73c\ub85c \uc5bc\ub9c8\ub098 \uc55e/\ub4a4 \ub0a0\uc9dc\ub85c \ubc1c\ud589\ud560\uc9c0 \uc124\uc815\ud569\ub2c8\ub2e4.\n(-: \uacfc\uac70, +: \ubbf8\ub798, 0\uc77c = \uc624\ub298)";
    constexpr const char* LOG_DATE_TODAY_HINT        = "(\uc624\ub298)";

    constexpr const char* SOAR_PANEL_SECTION         = "SOAR Mock API \uc11c\ubc84";
    constexpr const char* SOAR_PORT_LABEL            = "\ud3ec\ud2b8";
    constexpr const char* SOAR_BTN_START             = "\uc2dc\uc791";
    constexpr const char* SOAR_BTN_STOP              = "\uc911\uc9c0";
    constexpr const char* SOAR_BTN_RELOAD            = "\ub8f0 \ub9ac\ub85c\ub4dc";
    constexpr const char* SOAR_BTN_CONNECT           = "\uc5f0\uacb0 \uc124\uc815 \uc801\uc6a9";
    constexpr const char* SOAR_STATUS_RUNNING        = "\u25cf \uc218\uc2e0 \uc911";
    constexpr const char* SOAR_STATUS_STOPPED        = "\u25cf \uc911\uc9c0\ub428";
    constexpr const char* SOAR_STATUS_PORT_ERROR     = "\u25cf \ud3ec\ud2b8 \ubc14\uc778\ub529 \uc2e4\ud328";
    constexpr const char* SOAR_TOTAL_RECV_LABEL      = "\uc644 \uc218\uc2e0";
    constexpr const char* SOAR_RULE_LIST_LABEL       = "\ub85c\ub4dc\ub41c Mock \ub8f0";
    constexpr const char* SOAR_NO_RULES              = "  templates/api_mocks/ \uc5d0 YAML \ud30c\uc77c\uc774 \uc5c6\uc2b5\ub2c8\ub2e4";
    constexpr const char* SOAR_TAB_LOG               = "\ub85c\uadf8 \ubaa8\ub2c8\ud130";
    constexpr const char* SOAR_TAB_SOAR              = "SOAR Mock";
    constexpr const char* SOAR_LABEL_ENDPOINT        = "\uc5d4\ub4dc\ud3ec\uc778\ud2b8";
    constexpr const char* SOAR_LABEL_REQUEST_LOG     = "API \uc694\uccad \ub85c\uadf8";
    constexpr const char* SOAR_COL_TIME              = "\uc2dc\uac01";
    constexpr const char* SOAR_COL_METHOD            = "\uba54\uc11c\ub4dc";
    constexpr const char* SOAR_COL_PATH              = "\uacbd\ub85c";
    constexpr const char* SOAR_COL_STATUS            = "\uc0c1\ud0dc";

} // namespace UIText
