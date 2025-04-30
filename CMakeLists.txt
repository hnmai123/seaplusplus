cmake_minimum_required(VERSION 3.10)
project(SeaPlusPlus)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Source files
set(SOURCES
    main.cpp
    Angler.cpp
)

# Header files
set(HEADERS
    Angler.h
)

# Create executable
add_executable(SeaPlusPlus ${SOURCES} ${HEADERS})