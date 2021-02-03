cmake_minimum_required(VERSION 3.17)
project(test)

set(CMAKE_CXX_STANDARD 17)

add_executable(test main.cpp Class/Dessin.cpp Class/Dessin.h Class/Forme.cpp Class/Forme.h Class/Rectangle.cpp Class/Rectangle.h Class/Cercle.cpp Class/Cercle.h Class/Point.cpp Class/Point.h Class/Polygone.cpp Class/Polygone.h Class/Segment.cpp Class/Segment.h)