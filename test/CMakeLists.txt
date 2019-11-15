cmake_minimum_required(VERSION 3.1)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 /WX")
    if(MSVC_VERSION GREATER 1900)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /permissive-")
    endif()
else (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif (MSVC)

option(WITH_COVERAGE OFF)

if (WITH_COVERAGE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

add_executable(test_Array test_Array.cpp Allocators.h)
target_link_libraries(test_Array PRIVATE containers)

add_executable(test_List test_List.cpp Allocators.h)
target_link_libraries(test_List PRIVATE containers)

add_executable(test_Stack test_Stack.cpp Allocators.h)
target_link_libraries(test_Stack PRIVATE containers)

add_test(NAME Array COMMAND $<TARGET_FILE:test_Array>)
add_test(NAME List COMMAND $<TARGET_FILE:test_List>)
add_test(NAME Stack COMMAND $<TARGET_FILE:test_Stack>)
