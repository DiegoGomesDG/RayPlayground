cmake_minimum_required(VERSION 4.1)
project(RayTracing)

set(CMAKE_CXX_STANDARD 20)

# Add subprojects to the build.
# Each subdirectory contains its own CMakeLists.txt and defines targets
# that become part of this overall project.
add_subdirectory(RayTracing)
add_subdirectory(Core)