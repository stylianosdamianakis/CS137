cmake_minimum_required(VERSION 3.26)
project(CS137_Code C)

set(CMAKE_C_STANDARD 11)

add_executable(CS137_Code main.c
        a1/division.c
        a1/divisible9.c
        a1/grades.c
        a2/snake.c
        a2/functions.h
        a2/functions.c
        a3/pairs.c
        a3/jumpstairs.c
        a3/narcissistic.c
)
