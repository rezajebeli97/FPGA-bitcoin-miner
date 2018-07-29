cmake_minimum_required(VERSION 3.8)
project(clion_projects)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp crypto.cpp crypto.h)
add_executable(clion_projects ${SOURCE_FILES})