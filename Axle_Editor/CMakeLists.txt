project(Axle_Editor)

file(GLOB AXLE_EDITOR_SOURCES "src/*.cpp" "src/*.h")

add_executable(Axle_Editor ${AXLE_EDITOR_SOURCES})

# Link Axle library and its include directories
target_link_libraries(Axle_Editor PRIVATE Axle)
target_include_directories(Axle_Editor PRIVATE
    $<TARGET_PROPERTY:Axle,INTERFACE_INCLUDE_DIRECTORIES>
)