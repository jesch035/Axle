project(imgui)

file(GLOB IMGUI_SOURCES "*.cpp" "*.h")

add_library(imgui STATIC ${IMGUI_SOURCES})

target_include_directories(imgui INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
