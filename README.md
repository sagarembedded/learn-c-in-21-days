# Learn C in 21 Days - Setup and Getting Started

Welcome to the "Learn C in 21 Days" repository! This guide will help you clone the repo and set up your development environment on Windows using Visual Studio Code, MinGW, and CMake.

---

## 1. Clone the Repository

Open a terminal (Command Prompt or PowerShell) and run:

```bash
git clone https://github.com/sagarembedded/learn-c-in-21-days.git
cd learn-c-in-21-days
```

---

## 2. Install Prerequisites

To build and run the C programs, install the following tools:

### Visual Studio Code

- Download and install from [Visual Studio Code](https://code.visualstudio.com/) and during setup:
  - Add VS Code to PATH
  - Register VS Code as editor for supported file types
  - Add “Open with Code” in Windows Explorer context menu

Verify installation:

```bash
code --version
```

### MinGW-w64 (GCC Compiler)

- Visit: [https://www.mingw-w64.org/](https://www.mingw-w64.org/)
- Download the Win64 build for x86_64 architecture
- Install or extract to a simple folder like `C:\mingw-w64`
- Add `C:\mingw-w64\bin` to your system PATH (via Environment Variables)

Verify installation:

```bash
gcc --version
g++ --version
```

### CMake

- Download Windows installer from: [https://cmake.org/download/](https://cmake.org/download/)
- During installation, choose to add CMake to system PATH
- Verify installation:

```bash
cmake --version
```

---

## 3. Configure Visual Studio Code

- Open VS Code and install these extensions:
  - C/C++ (by Microsoft)
  - CMake Tools (optional)
- Open Command Palette (Ctrl+Shift+P)  `C/C++: Edit Configurations (UI)`
- Set Compiler path to your MinGW GCC executable, e.g.:

```
C:\mingw-w64\bin\gcc.exe
```

---

## 4. Daily Topics

- **Day 1:** Introduction and Setup
- **Day 2:** Basic Syntax and Data Types
- **Day 3:** Control Flow: If, Switch
- **Day 4:** Loops: For, While, Do-While
- **Day 5:** Functions and Recursion
- **Day 6:** Arrays and Strings
- **Day 7:** Pointers Basics
- **Day 8:** Advanced Pointers
- **Day 9:** Structures and Unions
- **Day 10:** File I/O
- **Day 11:** Dynamic Memory Allocation
- **Day 12:** Preprocessor Directives
- **Day 13:** Error Handling
- **Day 14:** Modular Programming
- **Day 15:** Linked Lists
- **Day 16:** Stacks and Queues
- **Day 17:** Searching and Sorting Algorithms
- **Day 18:** Bitwise Operations
- **Day 19:** Multi-file Projects
- **Day 20:** Basic Data Structures
- **Day 21:** Project: Small C Application

---

## 5. Build and Run Your Code

### Using CMake

From terminal in the repo folder:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Using VS Code Build Task

Press `Ctrl+Shift+B` to build using predefined tasks for daily exercises (e.g., `day01/main.c`).

Run the compiled executable from the terminal:

```bash
./day01/day01.exe
```

---

## 6. Daily Learning Workflow

- Explore folders `day01` through `day21`.
- Edit or review C source code.
- Build and run to understand C concepts practically.

---

## 7. Useful Links

- MinGW-w64: https://www.mingw-w64.org/
- CMake: https://cmake.org/

---

Happy coding on your journey to learn C!
