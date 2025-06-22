project(AxleEditor)

file(GLOB AXLE_EDITOR_SOURCES "src/*.cpp" "src/*.h")

add_executable(AxleEditor ${AXLE_EDITOR_SOURCES})

# Link Axle library and its include directories
target_link_libraries(AxleEditor PRIVATE Axle)
target_include_directories(AxleEditor PRIVATE
    $<TARGET_PROPERTY:Axle,INTERFACE_INCLUDE_DIRECTORIES>
)