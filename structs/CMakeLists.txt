cmake_minimum_required(VERSION 3.17)
project(structs C)

set(CMAKE_C_STANDARD 99)

add_subdirectory("${PROJECT_SOURCE_DIR}/2_10" "${PROJECT_SOURCE_DIR}/2_10/cmake-build-debug")
add_subdirectory("${PROJECT_SOURCE_DIR}/2_01" "${PROJECT_SOURCE_DIR}/2_01/cmake-build-debug")
add_subdirectory("${PROJECT_SOURCE_DIR}/2_06" "${PROJECT_SOURCE_DIR}/2_06/cmake-build-debug")
add_subdirectory("${PROJECT_SOURCE_DIR}/2_11" "${PROJECT_SOURCE_DIR}/2_11/cmake-build-debug")
add_subdirectory("${PROJECT_SOURCE_DIR}/2_13" "${PROJECT_SOURCE_DIR}/2_13/cmake-build-debug")
add_subdirectory("${PROJECT_SOURCE_DIR}/2_18" "${PROJECT_SOURCE_DIR}/2_18/cmake-build-debug")
add_subdirectory("${PROJECT_SOURCE_DIR}/structs_lib" "${PROJECT_SOURCE_DIR}/structs_lib/cmake-build-debug")
