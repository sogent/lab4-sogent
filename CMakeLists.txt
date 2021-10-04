cmake_minimum_required(VERSION 3.20)
project(lab4-sogent)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab4-sogent
        CS201L_Fall2021_Lab4-1.docx
        Lab04.cpp
        README.md calc3DDistModule.cpp calc3DDistModule.h)
