project(Axle)

file(GLOB AXLE_SOURCES "src/*.cpp" "src/*.h")

#source_group("Function" FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/function.cpp)

add_library(Axle SHARED ${AXLE_SOURCES})

target_compile_definitions(Axle PUBLIC AX_PLATFORM_WINDOWS PRIVATE AX_BUILD_DLL)

# Add this line if your headers are in src/
target_include_directories(Axle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../extern/spdlog/include ${CMAKE_CURRENT_SOURCE_DIR}/src )