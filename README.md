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
<pre>
├── App.cpp / App.h                  # Facade controller class 
├── Angler.cpp / Angler.h            # Stores angler info and manages their bag of catches 
├── CSVLoader.cpp / CSVLoader.h      # Utility class to load species rules from CSV files
├── SpeciesRule.h                    # Struct definition for species size and bag limit rules
├── SeaCreature.cpp / SeaCreature.h  # Abstract base class for all sea creatures
├── VertebrateCreature.cpp / .h      # Represents vertebrate species (no eggs)
├── InvertebrateCreature.cpp / .h    # Represents invertebrate species (may have eggs)
├── SeaChecker.cpp / .h              # Interface for rule checkers
├── InvertebrateChecker.cpp / .h     # Validates invertebrate creatures against rules
├── VertebrateChecker.cpp / .h       # Validates vertebrate creatures against rules
├── SeaPlusPlusEngine.cpp / .h       # Mediator pattern – coordinates validation logic
├── InputHelper.cpp / InputHelper.h  # Handles safe user input (with validation and formatting)
├── regulation/                      # Folder containing CSV rule files (size/bag limits)
├── main.cpp                         # Entry point that launches the App
├── CMakeLists.txt                   # CMake build configuration file
</pre>

## 📊 UML diagram
The following UML class diagram illustrates the structure and relationships of the Sea++ system as implemented in Part I.

🧩 **Design Patterns Used**:
- `<<facade>>` — **App**: Central entry point for user interaction and coordination.
- `<<mediator>>` — **SeaPlusPlusEngine**: Decouples sea creature validation logic from the App by mediating between checkers.
- `<<interface>>` — **SeaChecker**: Provides a common interface for all rule-checking classes.
  
🔁 **Key Relationships**:
- `SeaCreature` is an abstract base class, with `VertebrateCreature` and `InvertebrateCreature` as its subclasses.
- `SeaPlusPlusEngine` holds both `VertebrateChecker` and `InvertebrateChecker`, and delegates checking responsibilities.
- `SeaChecker` is an interface that both checker classes implement.
- `CSVLoader` statically loads rule data into a `map<string, SpeciesRule>` used by both checkers.
- `App` controls the flow of the program and interacts with `Angler`, `SeaPlusPlusEngine`, and the user.
  
![Part1_UML drawio](https://github.com/user-attachments/assets/f90df02f-b291-4371-aa74-1b834f634de7)

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

