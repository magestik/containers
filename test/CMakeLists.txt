cmake_minimum_required(VERSION 3.1)

include(CheckCXXCompilerFlag)

check_cxx_compiler_flag(-fno-sanitize=address HAVE_FLAG_SANITIZE_ADDRESS)

if (HAVE_FLAG_SANITIZE_ADDRESS)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
endif (HAVE_FLAG_SANITIZE_ADDRESS)

add_executable(test_Array test_Array.cpp Allocators.h)
target_link_libraries(test_Array PRIVATE containers)

add_executable(test_List test_List.cpp Allocators.h)
target_link_libraries(test_List PRIVATE containers)

add_executable(test_Stack test_Stack.cpp Allocators.h)
target_link_libraries(test_Stack PRIVATE containers)

add_test(NAME Array COMMAND $<TARGET_FILE:test_Array>)
add_test(NAME List COMMAND $<TARGET_FILE:test_List>)
add_test(NAME Stack COMMAND $<TARGET_FILE:test_Stack>)
