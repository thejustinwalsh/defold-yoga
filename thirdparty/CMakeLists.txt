cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_VERBOSE_MAKEFILE on)
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib)

add_compile_options(
    -fno-omit-frame-pointer
    -fexceptions
    -fvisibility=hidden
    -ffunction-sections
    -fdata-sections
    -Wall
    -std=c++11)

file(GLOB_RECURSE yogacore_SRC yoga/yoga/*.cpp)
add_library(yogacore STATIC ${yogacore_SRC})

target_include_directories(yogacore PUBLIC ./yoga)
