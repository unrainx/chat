cmake_minimum_required(VERSION 3.5)

project(Chat)

include_directories("${PROJECT_BINARY_DIR}")

file(GLOB_RECURSE mains RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
