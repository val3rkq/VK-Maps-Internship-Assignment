cmake_minimum_required(VERSION 3.10)

project(GraphBFS)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(GraphBFS src/main.cpp src/Graph/Graph.hpp)

target_link_libraries(GraphBFS PRIVATE stdc++fs)