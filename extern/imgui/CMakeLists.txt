project(imgui)

file(GLOB IMGUI_SOURCES "imgui/*.cpp" "imgui/*.h")

add_library(imgui STATIC ${IMGUI_SOURCES})

target_include_directories(imgui INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})