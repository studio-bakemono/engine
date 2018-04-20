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

#find_package (SDL2 REQUIRED)
#include_directories (${SDL2_INCLUDE_DIR})
#target_link_libraries(sbs ${SDL2_LIBRARY})

#Extra search locations, because magnus has his in an odd place
set(SDL2_SEARCH ${CMAKE_CURRENT_SOURCE_DIR}/../sdl2/)

find_package (SDL2 REQUIRED)
find_package (SDL2_image REQUIRED)
target_include_directories (sbs PUBLIC ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(sbs ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})
