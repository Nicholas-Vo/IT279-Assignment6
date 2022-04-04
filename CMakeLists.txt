cmake_minimum_required(VERSION 3.21)
project(assign6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assign6
        a4_app.cpp
        BinarySearchTree.cpp
        BinarySearchTree.h
        dsexceptions.h
        SeparateChain.cpp
        SeparateChain.h
        Student.cpp
        Student.h)
