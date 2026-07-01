# C++23을 안정적으로 지원하는 3.25 버전으로 상향
# (std::expected, std::flat_map 등 C++23 feature-test macro 정확 처리)
cmake_minimum_required(VERSION 3.25)
project(SIMLogGenerator VERSION 1.0.0 LANGUAGES CXX)

# ==============================================================================
# 1. C++23 표준 및 컴파일러 확장 제어
# ==============================================================================
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 컴파일러별 비표준 확장(gnu++23 등)을 차단하여 순수 C++23 표준 준수 강제
set(CMAKE_CXX_EXTENSIONS OFF)

# ==============================================================================
# 2. 외부 패키지 의존성
# ==============================================================================
find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(implot CONFIG REQUIRED)
find_package(httplib CONFIG REQUIRED)

# ==============================================================================
# 3. 소스 파일 수집 (모던 CMake 방식 보완)
# ==============================================================================
# CONFIGURE_DEPENDS: 새 파일 추가 시 CMake이 자동으로 변경을 감지하고 재구성
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "src/*.cpp"
    "src/*.h"
)

if(WIN32)
    list(APPEND SOURCES "src/resources.rc")
endif()

# ==============================================================================
# 4. 실행 파일 타겟 생성 및 속성 설정
# ==============================================================================
add_executable(${PROJECT_NAME} ${SOURCES})

if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
    if(MSVC)
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/ENTRY:mainCRTStartup")
    endif()
endif()

target_include_directories(${PROJECT_NAME} PRIVATE src)

# ==============================================================================
# 5. 컴파일러 경고 옵션 (모던 타겟 기반)
# ==============================================================================
add_library(SIMLogGenerator_Warnings INTERFACE)

if(MSVC)
    target_compile_options(SIMLogGenerator_Warnings INTERFACE
        /W4
        /WX
        /permissive-
        # __cplusplus 매크로가 실제 표준값을 반환하도록 강제
        # (이 플래그 없으면 _cplusplus == 199711L 로 고정되어
        #  C++23 기능 조건부 활성화 불가)
        /Zc:__cplusplus
        # MSVC /std:c++23 이 아직 모든 버전에서 지원되지 않으므로
        # latest 로 C++23 지원 보장
        /std:c++latest
    )
    target_compile_definitions(${PROJECT_NAME} PRIVATE _CRT_SECURE_NO_WARNINGS)
else()
    target_compile_options(SIMLogGenerator_Warnings INTERFACE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
        # std::hardware_destructive_interference_size 사용에 의한
        # -Winterference-size 경고 억제
        # (GCC 12+ 에서 만 발생, Clang 에서는 무시됨)
        -Wno-interference-size
    )
endif()

# 경고 타겟을 메인 프로젝트에 링크
target_link_libraries(${PROJECT_NAME} PRIVATE SIMLogGenerator_Warnings)

# ==============================================================================
# 6. 라이브러리 링킹 (공통 및 플랫폼 종속)
# ==============================================================================
target_link_libraries(${PROJECT_NAME} PRIVATE
    imgui::imgui
    glfw
    OpenGL::GL
    nlohmann_json::nlohmann_json
    fmt::fmt
    implot::implot
    httplib::httplib
)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32)
elseif(APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
    )
elseif(UNIX)
    find_package(X11 REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        X11::X11
        pthread
        dl
    )
    target_link_libraries(${PROJECT_NAME} PRIVATE anl)
endif()

# ==============================================================================
# 7. 빌드 후 에셋 복사 명령
# ==============================================================================
foreach(DIR assets config templates ti_data)
    if(EXISTS "${CMAKE_SOURCE_DIR}/${DIR}")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${CMAKE_SOURCE_DIR}/${DIR}"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${DIR}"
            COMMENT "Copying ${DIR} to build output"
        )
    endif()
endforeach()

if(EXISTS "${CMAKE_SOURCE_DIR}/imgui.ini")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_SOURCE_DIR}/imgui.ini"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/imgui.ini"
        COMMENT "Copying imgui.ini to build output"
    )
endif()
