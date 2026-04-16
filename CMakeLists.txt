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

# Modules
add_subdirectory(Core)
add_subdirectory(RayTracing)