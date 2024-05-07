cmake_minimum_required(VERSION 3.0.0)

project(Perceptron LANGUAGES CXX)
include_directories(include)

file(GLOB SRCS src/*.cpp main.cpp)
add_library(Perceptron STATIC ${SRCS})

set_property(TARGET Perceptron PROPERTY POSITION_INDEPENDENT_CODE ON)
set_target_properties(Perceptron PROPERTIES OUTPUT_NAME Perceptron)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-error -pedantic -fsanitize=address,undefined -std=c++11 -lm -lX11 -lpthread" )

set(TARGET_HEADERS include)

add_executable("prog_${PROJECT_NAME}" ${SRCS} ${TARGET_HEADERS})

