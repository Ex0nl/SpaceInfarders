cmake_minimum_required(VERSION 3.20) 
project(spaceinfarders)
add_executable(spaceinfarders src/main.cpp)

target_link_directories(spaceinfarders PRIVATE lib/)
target_link_libraries(spaceinfarders PRIVATE glfw3 opengl32 gdi32 glu32)

include_directories(include/)
