cmake_minimum_required(VERSION 3.10)
project(Coat_of_arms)

set(CMAKE_CXX_STANDARD 11)

add_executable(Coat_of_arms main.cpp blazon.h duct.h duct.cpp create_duct.cpp create_duct.h blazon.cpp blazon_builder.cpp blazon_builder.h)