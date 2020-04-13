cmake_minimum_required(VERSION 3.0)
project(JWT_ABC)

set(CMAKE_CXX_STANDARD 14)

link_libraries(crypto)

include_directories(include)

add_executable(JWT_ABC main.cpp)