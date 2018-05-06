cmake_minimum_required (VERSION 2.6)
project (opengl_test)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

link_libraries(${OPENGL_LIBRARIES})
link_libraries(${GLUT_LIBRARIES})

add_executable(opengl_test main.cpp)

