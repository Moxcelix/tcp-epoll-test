cmake_minimum_required(VERSION 3.20)
project(TCPEpollTest VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cpp")

file(GLOB_RECURSE HEADERS "include/*.hpp")

add_executable(tcp_epoll_test ${SOURCES})

target_include_directories(tcp_epoll_test PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(tcp_epoll_test PRIVATE -Wall -Wextra -pedantic)