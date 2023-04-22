cmake_minimum_required(VERSION 3.25)
project(base)

set(CMAKE_CXX_STANDARD 17)

add_executable(base main.cpp workerManger.h workerManger.cpp worker.h employee.h employee.cpp)
