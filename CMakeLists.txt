cmake_minimum_required(VERSION 3.28)
project(WakeandConnect)

set(CMAKE_CXX_STANDARD 17)

add_executable(WakeandConnect main.cpp
        include/socket_utils.h
        src/socket_utils.cpp
        include/protocols.h
        src/protocols.cpp
        include/server.h
        src/server.cpp
)
