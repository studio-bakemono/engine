cmake_minimum_required(VERSION 3.4)
project(sbsEngine)

#For FindSDL2.cmake
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

include(cmake/version.cmake)
#include(cmake/.cmake)
#include(cmake/.cmake)

file(GLOB_RECURSE SOURCE_C "${CMAKE_SOURCE_DIR}/src/*.c*")
file(GLOB_RECURSE SOURCE_H "{CMAKE_SOURCE_DIR}/src/*.h*")

set(CMAKE_CXX_STANDARD 17)

add_executable(sbs ${SOURCE_C} ${SOURCE_H})

find_package (SDL2 REQUIRED)
include_directories (${SDL2_INCLUDE_DIR})
target_link_libraries(sbs ${SDL2_LIBRARY})
