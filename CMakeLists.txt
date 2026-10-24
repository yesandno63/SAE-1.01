cmake_minimum_required(VERSION 4.3)
project(SAE_1_01 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(SAE_1_01
        programme.c
        prototype.h
        testepgrm.c)
