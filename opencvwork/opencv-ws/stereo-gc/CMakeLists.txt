# cmake needs this line 
cmake_minimum_required(VERSION 2.8) 

# Enable C++11 
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED TRUE) 
set(OpenCV_DIR /usr/local/opencv3.4.1/share/OpenCV)

# Define project name 
project(stereo-gc) 

SET(CMAKE_BUILD_TYPE Release)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Find OpenCV, you may need to set OpenCV_DIR variable 
# to the absolute path to the directory containing OpenCVConfig.cmake file 
# via the command line or GUI 

FIND_PACKAGE(OpenCV 3.4.1 REQUIRED)

message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

include_directories(SYSTEM ${OpenCV_INCLUDE_DIRS} /usr/local/opencv3.4.1/include) #新复制过来的是没有这一行的，自己加的 

# Declare the executable target built from your sources 
add_executable(stereo-gc src/stereo-GC.cpp)

# Link your application with OpenCV libraries 
target_link_libraries(${OpenCV_LIBRARY_DIRS} /usr/local/opencv3.4.1/lib)
