cmake_minimum_required(VERSION 3.8)
project(Scrabble_after_omnia_changes)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Bag.cpp Bag.h Board.cpp Board.h Player.cpp Player.h Move.h Judge.cpp Judge.h Source.cpp)
add_executable(Scrabble_after_omnia_changes ${SOURCE_FILES})