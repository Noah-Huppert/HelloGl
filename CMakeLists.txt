cmake_minimum_required(VERSION 2.8.4)
project(HelloGl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(GLIB_LIB_DIR libs/glib/Debug)
set(GLIB_INCLUDE_DIR libs/glib/include)

set(GLFW_LIB_DIR libs/glfw/lib)

include_directories(${GLIB_INCLUDE_DIR})
link_directories(${GLIB_LIB_DIR})
link_directories(${GLFW_LIB_DIR})

set(SOURCE_FILES src/main.cpp)

add_executable(HelloGl ${SOURCE_FILES})

target_link_libraries (HelloGl glfw3)
target_link_libraries (HelloGl glib)
target_link_libraries (HelloGl opengl32)