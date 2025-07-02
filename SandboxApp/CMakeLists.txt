project(SandboxApp)

file(GLOB SANDBOX_APP_SOURCES "src/*.cpp" "src/*.h")

source_group("src" FILES ${SANDBOX_APP_SOURCES})

add_executable(SandboxApp ${SANDBOX_APP_SOURCES})

target_link_libraries(SandboxApp PRIVATE Axle)