cmake_minimum_required(VERSION 3.10)
project(ThreadPool)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include header files from include/
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add source files
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})
