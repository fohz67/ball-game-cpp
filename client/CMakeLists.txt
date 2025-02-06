cmake_minimum_required(VERSION 3.20)
project(client)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES src/*.cpp src/**/*.cpp)
file(GLOB_RECURSE HEADERS include/*.hpp include/**/*.hpp)

add_executable(Client ${SOURCES} ${HEADERS})

target_include_directories(Client PUBLIC include ${CMAKE_SOURCE_DIR}/smart-buffer-cpp/include ${CMAKE_SOURCE_DIR}/asio/asio/include)
target_link_libraries(Client sfml-graphics sfml-window sfml-system sfml-audio smart_buffer GameEngine)
