cmake_minimum_required(VERSION 3.15)

project(languageII LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(lii src/main.cpp src/interpreter.cpp src/compiler.cpp)
