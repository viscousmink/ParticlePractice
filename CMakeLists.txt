cmake_minimum_required(VERSION 3.22)

project(
  ParticlePractice
  VERSION 1.0
  LANGUAGES CXX C)

add_subdirectory(include/glfw-3.4)
include_directories(include/glad)

set(SOURCE_FILES
    main.cpp
    Shader.cpp
    Window.cpp
    Mesh.cpp
    glad.c
)

add_executable(ParticlePractice ${SOURCE_FILES})

target_link_libraries(ParticlePractice glfw)
target_compile_features(ParticlePractice PUBLIC cxx_std_17)
