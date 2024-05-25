cmake_minimum_required(VERSION 3.22)

project(
  ParticlePractice
  VERSION 1.0
  LANGUAGES CXX C)

add_subdirectory(include/glfw-3.4)
include_directories(include/glad)

add_executable(ParticlePractice main.cpp glad.c)

target_link_libraries(ParticlePractice glfw)
