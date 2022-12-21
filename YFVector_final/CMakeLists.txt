cmake_minimum_required(VERSION 3.23)
project(YFVector2)

set(CMAKE_CXX_STANDARD 14)

add_executable(YFVector2 main.cpp YFVector.h YFVector.cpp exceptions.h)
