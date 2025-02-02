cmake_minimum_required(VERSION 3.20)
project(gengine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES src/*.cpp src/**/*.cpp)
file(GLOB_RECURSE HEADERS include/*.hpp include/**/*.hpp)

add_library(GEngine STATIC ${SOURCES})

target_include_directories(GEngine PUBLIC include)
target_link_libraries(GEngine sfml-graphics sfml-window sfml-system smart_buffer)
