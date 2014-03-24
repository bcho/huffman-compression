cmake_minimum_required(VERSION 2.8)
project(huffman-compression)


set(CMAKE_C_FLAGS "-Wall -g")

include_directories(./src)

add_subdirectory(./src)
add_subdirectory(./tests)
add_subdirectory(./draft)
