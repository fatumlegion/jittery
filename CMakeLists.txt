project (jittery)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

set (jt_SRCS
	src/main.cpp
	src/Application.cpp
	src/AssetContainer.cpp
	src/TestWorld.cpp
	src/Player.cpp
)

set (jt_LIBS
	sfml-graphics
	sfml-window
	sfml-audio
	sfml-system
)

add_executable(a ${jt_SRCS})
target_link_libraries(a ${jt_LIBS})