cmake_minimum_required(VERSION 2.8.12)

include(CheckCCompilerFlag)

check_c_compiler_flag(-fno-sanitize=address HAVE_FLAG_SANITIZE_ADDRESS)

if (HAVE_FLAG_SANITIZE_ADDRESS)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
endif (HAVE_FLAG_SANITIZE_ADDRESS)

file(GLOB_RECURSE HEADERS ../include/*.h ../include/*.inl)

add_executable(simple_test test.cpp ${HEADERS})

target_include_directories(simple_test PRIVATE ../include/)

set_property(TARGET simple_test PROPERTY CXX_STANDARD 11)

