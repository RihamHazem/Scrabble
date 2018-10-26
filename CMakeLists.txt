cmake_minimum_required(VERSION 3.8)
project(Scrabble)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Bag.cpp Bag.h Board.cpp Board.h Player.cpp Player.h Move.h Judge.cpp Judge.h)
add_executable(Scrabble ${SOURCE_FILES})