cmake_minimum_required(VERSION 3.1)

project(containers CXX)

enable_testing()
include(CTest)

add_library(containers INTERFACE)

target_include_directories(containers INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_features(containers INTERFACE cxx_nullptr)

if (BUILD_TESTING)
    add_subdirectory(test)
endif()
