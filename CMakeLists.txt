cmake_minimum_required(VERSION 2.8.12)

add_library(containers INTERFACE)

target_include_directories(containers INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_subdirectory(test)
