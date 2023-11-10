cmake_minimum_required(VERSION 3.26)
project(CS137_Code C)

set(CMAKE_C_STANDARD 11)

add_executable(CS137_Code main.c
        a3/jumpstairs.c
        a4/grades.c
        a4/matrix.c
        a4/trapezoidal.c
        a5/flexdata.c
        a5/company.c
        a5/rec.c
        a6/vlinteger.c
        a6/vlinteger.h
        a6/bank.c
        a6/bank.h
        a6/bankmain.c
        a7/semidrome.c
)
