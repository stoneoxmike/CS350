cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_OSX_ARCHITECTURES "x86_64")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

project(lab05)
set(SOURCE_FILES
    main.cpp)

add_executable(lab05 ${SOURCE_FILES})
set_target_properties(lab05 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR} )
