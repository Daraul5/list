cmake_minimum_required(VERSION 4.0)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        libro.cpp
        libro.h
        lista.h
        ListaSimple.cpp
        ListaSimple.h)
