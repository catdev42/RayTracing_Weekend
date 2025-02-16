cmake_minimum_required(VERSION 3.10)
project(raytracer)

# Set C++11 as minimum
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create executable from main.cc
add_executable(raytracer main.cc)

# COMMANDS:
# cd build; cmake ..; make; ./raytracer > image.ppm; cd ..
# cd build; python3 view_ppm.py; cd .. 
