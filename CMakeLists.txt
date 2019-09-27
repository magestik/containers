cmake_minimum_required(VERSION 3.1)

project(containers CXX)

enable_testing()

add_library(containers INTERFACE)

target_include_directories(containers INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_subdirectory(test)
