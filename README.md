# Sea++ (Part I)

## 🎣 Description

Sea++ is a C++ application that helps recreational anglers determine whether a caught sea creature can be legally kept or must be released, based on NSW fishing regulations.

This repository contains the **Part I** implementation of the Sea++ project, focusing on:
- Class design using object-oriented principles
- Application of design patterns
- Input validation and interaction with the user via CLI
  
## 🧠 Design Patterns Used
- **Facade Pattern**: The `App` class acts as the main interface between the angler and the rest of the system.
- **Mediator Pattern**: `SeaPlusPlusEngine` coordinates interaction between sea creatures and sea rule checkers.
- **Interface Pattern**: `SeaChecker` defines a uniform interface for `VertebrateChecker` and `InvertebrateChecker`.

## 📁 File Structure
├── App.cpp / App.h                  # Facade controller class <br>
├── Angler.cpp / Angler.h            # Stores angler info and manages their bag of catches <br>
├── CSVLoader.cpp / CSVLoader.h      # Utility class to load species rules from CSV files<br>
├── SpeciesRule.h                    # Struct definition for species size and bag limit rules<br>
├── SeaCreature.cpp / SeaCreature.h  # Abstract base class for all sea creatures<br>
├── VertebrateCreature.cpp / .h      # Represents vertebrate species (no eggs)<br>
├── InvertebrateCreature.cpp / .h    # Represents invertebrate species (may have eggs)<br>
├── SeaChecker.h                     # Interface for rule checkers (checkCatch method)<br>
├── InvertebrateChecker.cpp / .h     # Validates invertebrate creatures against rules<br>
├── VertebrateChecker.cpp / .h       # Validates vertebrate creatures against rules<br>
├── SeaPlusPlusEngine.cpp / .h       # Mediator pattern – coordinates validation logic<br>
├── InputHelper.cpp / InputHelper.h  # Handles safe user input (with validation and formatting)<br>
├── regulation/                      # Folder containing CSV rule files (size/bag limits)<br>
├── main.cpp                         # Entry point that launches the App<br>
├── CMakeLists.txt                   # CMake build configuration file<br>


## 📊 UML diagram
The following UML class diagram illustrates the structure and relationships of the Sea++ system as implemented in Part I.
🧩 **Design Patterns Used**:
- `<<facade>>` — **App**: Central entry point for user interaction and coordination.
- `<<mediator>>` — **SeaPlusPlusEngine**: Decouples sea creature validation logic from the App by mediating between checkers.
- `<<interface>>` — **SeaChecker**: Provides a common interface for all rule-checking classes.
📐 **Key Relationships**:
- `SeaCreature` is an abstract base class, with `VertebrateCreature` and `InvertebrateCreature` as its subclasses.
- `SeaPlusPlusEngine` holds both `VertebrateChecker` and `InvertebrateChecker`, and delegates checking responsibilities.
- `SeaChecker` is an interface that both checker classes implement.
- `CSVLoader` statically loads rule data into a `map<string, SpeciesRule>` used by both checkers.
- `App` controls the flow of the program and interacts with `Angler`, `SeaPlusPlusEngine`, and the user.
  
![Part1_UML drawio](https://github.com/user-attachments/assets/4106fa39-0042-42ff-b820-bfb339dd96b5)

## 🚀 How to Build & Run
Follow these steps to build and run the project manually:
```bash
# Step 1: Create the build directory
mkdir build
# Step 2: Move into the build directory
cd build
# Step 3: Generate the build system using CMake
cmake ..
# Step 4: Compile the project
make
# Step 5: Run the program
./SeaPlusPlus

