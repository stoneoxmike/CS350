cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_OSX_ARCHITECTURES "x86_64")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

project(lab06)
set(SOURCE_FILES
    Node.h
    Tree.h
    Tree.cpp
    PrettyPrinter.h
    PrettyPrinter.cpp
    main.cpp)

add_executable(lab06 ${SOURCE_FILES})
set_target_properties(lab06 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR} )
