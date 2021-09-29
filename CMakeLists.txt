cmake_minimum_required(VERSION 3.20)
project(BreakoutGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(BreakoutGame main.cpp Sources/Server.cpp Headers/Server.h Sources/Client.cpp Headers/Client.h Sources/Board.cpp Headers/Board.h Sources/Ball.cpp Headers/Ball.h)
