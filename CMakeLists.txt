cmake_minimum_required(VERSION 3.20)
project(RayTracingProject)

set(CMAKE_CXX_STANDARD 20)

# Third-party libraries
# GLFW
add_subdirectory(thirdparty/glfw)

# GLAD
add_library(glad STATIC
        thirdparty/glad/src/glad.c
)
target_include_directories(glad PUBLIC
        thirdparty/glad/include
)

# GLM
add_subdirectory(thirdparty/glm)

# ImGui (submodule)
add_library(imgui STATIC)

set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/imgui)
target_sources(imgui PRIVATE
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp

        ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC
        ${IMGUI_DIR}
        ${IMGUI_DIR}/backends
)

# Link GLFW and ImGui
target_link_libraries(imgui
        PUBLIC glfw glad
)

# Modules
add_subdirectory(Core)
add_subdirectory(RayTracing)