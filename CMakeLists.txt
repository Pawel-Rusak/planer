cmake_minimum_required(VERSION 3.24)
project(generator_planow)

set(CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")



add_executable(generator_planow main.cpp wyklady.cpp wyklady.cpp cwiczenia.cpp)
