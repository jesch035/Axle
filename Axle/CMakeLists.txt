project(Axle)

file(GLOB AXLE_ROOT_FILES "Axle/*.cpp" "Axle/*.h")
file(GLOB AXLE_EVENTS "Axle/Events/*.cpp" "Axle/Events/*.h")
file(GLOB AXLE_PLATFORM_WINDOWS "Platform/Windows/*.cpp" "Platform/Windows/*.h")
file(GLOB AXLE_INCLUDES "Include/*.h")

source_group("" FILES ${ROOT_FILES})
source_group("Axle" FILES ${AXLE_ROOT_FILES})
source_group("Axle\\Events" FILES ${AXLE_EVENTS})
source_group("Platform\\Windows" FILES ${AXLE_PLATFORM_WINDOWS})
source_group("Include" FILES ${AXLE_INCLUDES})

add_library(Axle SHARED ${ROOT_FILES} ${AXLE_ROOT_FILES} ${AXLE_EVENTS} ${AXLE_PLATFORM_WINDOWS} ${AXLE_INCLUDES})

target_link_libraries(Axle PUBLIC spdlog::spdlog imgui)

target_compile_definitions(Axle
	PUBLIC
	$<$<CONFIG:Debug>:AX_CONFIG_DEBUG>
	$<$<CONFIG:Release>:AX_CONFIG_RELEASE>
	AX_PLATFORM_WINDOWS PRIVATE AX_BUILD_DLL
)

target_precompile_headers(Axle PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Axle/pch.h)

target_include_directories(Axle 
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/Axle
	${CMAKE_CURRENT_SOURCE_DIR}/Axle/Events
	${CMAKE_CURRENT_SOURCE_DIR}/Platform/Windows
	INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/Include
)