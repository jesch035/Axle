cmake_minimum_required(VERSION 3.16)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

project(Axle)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>")

add_subdirectory(Axle)
add_subdirectory(SandboxApp)
add_subdirectory(extern/spdlog)
add_subdirectory(extern/imgui)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SandboxApp)