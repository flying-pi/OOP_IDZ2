cmake_minimum_required(VERSION 3.6)
project(IDZ2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp LOGIKA16.cpp LOGIKA16.h util.h util.cpp const.h OutPrinter.h OutPrinter.cpp TermianlUserInterface.cpp TermianlUserInterface.h)
add_executable(IDZ2 ${SOURCE_FILES})


set(SOURCE_FILES generator/main.cpp const.h)
add_executable(IDZ2_generator ${SOURCE_FILES})