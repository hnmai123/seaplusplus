cmake_minimum_required(VERSION 3.10)
project(SeaPlusPlus)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Source files
set(SOURCES
    main.cpp
    Angler.cpp
    App.cpp
    CSVLoader.cpp
    InvertebrateChecker.cpp
    InvertebrateCreature.cpp
    SeaCreature.cpp
    SeaPlusPlusEngine.cpp
    VertebrateChecker.cpp
    VertebrateCreature.cpp
)

# Header files
set(HEADERS
    Angler.h
    App.h
    CSVLoader.h
    InvertebrateChecker.h
    InvertebrateCreature.h
    SeaChecker.h
    SeaCreature.h
    SeaPlusPlusEngine.h
    VertebrateChecker.h
    VertebrateCreature.h
)

# Create executable
add_executable(SeaPlusPlus ${SOURCES} ${HEADERS})

# Copy regulation files to build directory
file(COPY ${CMAKE_SOURCE_DIR}/regulation/vertebrate_rules.csv
     DESTINATION ${CMAKE_BINARY_DIR}/regulation)

file(COPY ${CMAKE_SOURCE_DIR}/regulation/invertebrate_rules.csv
     DESTINATION ${CMAKE_BINARY_DIR}/regulation)
