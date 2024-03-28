cmake_minimum_required(VERSION 3.22.1)

project(variance_test)

find_program(gnuplot "gnuplot" REQUIRED)

add_executable(${PROJECT_NAME} 
   src/main.cpp
   src/stats.cpp)

set_property(TARGET variance_test PROPERTY CXX_STANDARD 11)