project(SandboxApp)

file(GLOB SANDBOX_APP_SOURCES "src/*.cpp" "src/*.h")

source_group("src" FILES ${SANDBOX_APP_SOURCES})

add_executable(SandboxApp ${SANDBOX_APP_SOURCES})

# Link Axle library and its include directories
target_link_libraries(SandboxApp PRIVATE Axle)
target_include_directories(SandboxApp PRIVATE
    $<TARGET_PROPERTY:Axle,INTERFACE_INCLUDE_DIRECTORIES>
)