cmake_minimum_required(VERSION 3.17)
project(structs_lib C)

set(CMAKE_C_STANDARD 99)

add_library(structs_lib library.c library.h)