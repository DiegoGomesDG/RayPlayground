add_library(Core STATIC)

file(GLOB_RECURSE CORE_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/stb_image/stb_image.cpp"
)

target_sources(Core PRIVATE ${CORE_SOURCES})

target_include_directories(Core
        PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/stb_image"
)

# GLAD
add_library(glad STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glad/src/glad.c
)

target_include_directories(glad PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glad/include
)

# GLFW
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glfw)

target_link_libraries(Core
        PUBLIC glfw glad
)