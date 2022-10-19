cmake_minimum_required(VERSION 3.23)
project(ntersection_of_HalfPlanes_with_the_box_)

set(CMAKE_CXX_STANDARD 17)

add_executable(ntersection_of_HalfPlanes_with_the_box_ main.cpp Vec.cpp Vec.h halfPlane.cpp halfPlane.h interAlg.cpp interAlg.h)
