cmake_minimum_required(VERSION 3.20)
project(BallGame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(${CMAKE_SOURCE_DIR}/SFML)
add_subdirectory(${CMAKE_SOURCE_DIR}/smart-buffer-cpp)
add_subdirectory(${CMAKE_SOURCE_DIR}/game_engine)
add_subdirectory(${CMAKE_SOURCE_DIR}/server)
add_subdirectory(${CMAKE_SOURCE_DIR}/client)
