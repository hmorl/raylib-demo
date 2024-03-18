cmake_minimum_required(VERSION 3.25)

project(raylib-demo)

include(cmake/CPM.cmake)
CPMAddPackage("gh:raysan5/raylib#5.0")

add_executable(raylib-demo)
set_target_properties(raylib-demo PROPERTIES CXX_STANDARD 20)

target_sources(raylib-demo PRIVATE
    src/main.cpp
)

target_include_directories(raylib-demo PRIVATE src)
target_link_libraries(raylib-demo PRIVATE raylib)

if(APPLE)
    target_link_libraries(raylib-demo PRIVATE "-framework IOKit")
    target_link_libraries(raylib-demo PRIVATE "-framework Cocoa")
    target_link_libraries(raylib-demo PRIVATE "-framework OpenGL")
endif()
