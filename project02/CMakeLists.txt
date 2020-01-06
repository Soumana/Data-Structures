cmake_minimum_required(VERSION 3.12)
project(project02)

set(CMAKE_CXX_STANDARD 17)

add_executable(project02 main.cpp Entity.cpp Entity.hpp EntityInstance.cpp EntityInstance.hpp JSONParser.cpp JSONParser.hpp JSONToken.cpp JSONToken.hpp JSONTokenizer.cpp JSONTokenizer.hpp Pair.cpp Pair.hpp)