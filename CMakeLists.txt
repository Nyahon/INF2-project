cmake_minimum_required(VERSION 3.7)
project(project)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c inscriptions.c inscriptions.h utils.c utils.h)
add_executable(project ${SOURCE_FILES})