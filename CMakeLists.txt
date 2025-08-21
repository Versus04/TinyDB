cmake_minimum_required(VERSION 3.10)
project(TinyDB) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(TinyDB
    src/main.cpp
    src/database.cpp
    src/parser.cpp
    src/table.cpp
)
