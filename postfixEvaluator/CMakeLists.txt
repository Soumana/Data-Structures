cmake_minimum_required(VERSION 3.14)
project(postfixEvaluator)

set(CMAKE_CXX_STANDARD 17)

add_executable(postfixEvaluator main.cpp Token.cpp Tokenizer.cpp)