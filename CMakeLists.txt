cmake_minimum_required(VERSION 3.28)

project(modules-example)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

add_library(lib STATIC)
target_sources(lib
        PUBLIC
        FILE_SET all_my_modules TYPE CXX_MODULES FILES
        a.cppm
        b.cppm
)
target_link_options(lib PRIVATE LINKER:--gc-sections)

add_executable(demo)
target_sources(demo
        PUBLIC
        main.cpp
)
target_link_libraries(demo PRIVATE lib)