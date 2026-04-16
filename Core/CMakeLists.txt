add_library(Core STATIC)

file(GLOB_RECURSE CORE_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

target_sources(Core PRIVATE ${CORE_SOURCES})

target_include_directories(Core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(Core PUBLIC GLFW_INCLUDE_NONE)

target_link_libraries(Core
        PUBLIC
        glfw
        glad
)