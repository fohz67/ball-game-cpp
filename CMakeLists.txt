cmake_minimum_required(VERSION 3.20)
project(BallGame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_SOURCE_DIR}/external/SFML)
add_subdirectory(${CMAKE_SOURCE_DIR}/external/smart-buffer-cpp)
#add_subdirectory(${CMAKE_SOURCE_DIR}/game_engine)
add_subdirectory(${CMAKE_SOURCE_DIR}/server)
add_subdirectory(${CMAKE_SOURCE_DIR}/client)
