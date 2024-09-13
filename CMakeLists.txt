cmake_minimum_required(VERSION 3.23)
project(AED_projeto)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AED_projeto
        classes.h
        classes_per_uc.h
        func_auxiliares.cpp
        main.cpp
        projeto.cpp
        Request.cpp
        Request.h
        SaveStudents.cpp
        Student.h)
