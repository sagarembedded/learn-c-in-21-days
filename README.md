<p align="center">
  <img src="https://raw.githubusercontent.com/sagarembedded/learn-c-in-21-days/refs/heads/main/banner.png" alt="EmbeddedHub"  width="500x500"/>
</p>

<h1 align="center">C Programming – 21 Day Mastery Roadmap</h1>
<p align="center">
  <strong>Structured, practical, hands-on roadmap for mastering C programming</strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" alt="Language: C"/>
  <img src="https://img.shields.io/badge/License-MIT-green.svg" alt="License"/>
  <img src="https://img.shields.io/badge/Build-Pending-lightgrey.svg" alt="Build Status"/>
</p>

---

## 🌟 Overview

This repository provides a **21-day learning roadmap for C**, combining the structured approach of *Sams Teach Yourself C in 21 Days (6th Edition)* with practical insights from *Let Us C* by Yashavant Kanetkar.  

By following this roadmap, you will:

- Learn and apply core C concepts  
- Write clean, efficient C programs  
- Be ready for embedded systems and system-level programming  

The repository contains **day-wise folders** (`Day_01_Introduction` … `Day_21_Final_Project`) with:

- `README.md` for the day’s objectives and explanations  
- `examples/` folder with complete C code  
- `exercises.md` for practice problems and solutions  
- `.vscode/` folder pre-configured for building and debugging  

---

## 🟢 Get Started: Clone the Repository

Clone this repository to your local machine:

```bash
git clone https://github.com/yourusername/learn-c-in-21-days.git
```
Navigate into the project folder:
```bash
cd learn-c-in-21-days
```
Open the project in VS Code to start following the 21-day roadmap.

## 🛠️ Tools & Setup
### 1️⃣ MinGW (GCC Compiler)
- Download: [MinGW-w64](https://www.mingw-w64.org/downloads/)
- Add to PATH: C:\mingw-w64\bin
- Verify:
```bash
gcc --version
```
### 2️⃣ CMake
- Download: [CMake](https://cmake.org/download/)
- Verify:
```bash
cmake --version
```
### 3️⃣ Visual Studio Code
- Download: [VS Code](https://code.visualstudio.com/)
- Install extensions:
    - C/C++
    - CMake Tools
    - Code Runner (optional)

## 🚀 How to Compile & Run Examples
You can compile and run C programs using VS Code tasks (recommended) or the command line.

### 1️⃣ Using VS Code Tasks (Recommended)
1. Open any example file in VS Code, e.g., Day_01_Introduction/examples/example.c.
2. Press Ctrl+Shift+B to build the current file.
    * The executable will be created in the same folder as the source file.
3. Press F5 to run and debug the program using the configured debugger (launch.json).

This workflow automatically uses the .vscode/tasks.json and .vscode/launch.json configuration.

### 2️⃣ Using Command Line (Optional)
```bash
# Navigate to the example folder
cd Day_01_Introduction/examples

# Compile the C program
gcc example.c -o example.exe

# Run the compiled program
./example.exe
```
#### 💡 Tip: For multi-file projects, using CMake with VS Code is recommended.

## 📅 21-Day Roadmap Table

| Day | Objective                        | Description                                                        |
| --- | -------------------------------- | ------------------------------------------------------------------ |
| 1   | Introduction & Environment Setup | Learn about C history, tools, and first programs                   |
| 2   | Variables & Data Types           | Primitive types, type casting, constants, scope                    |
| 3   | Operators                        | Arithmetic, logical, bitwise, assignment, precedence               |
| 4   | Conditional Statements           | `if`, `if-else`, `switch` statements                               |
| 5   | Loops                            | `for`, `while`, `do-while`, break/continue                         |
| 6   | Functions                        | Declaration, definition, call, recursion, scope                    |
| 7   | Pointers                         | Pointer basics, arithmetic, pointer to functions                   |
| 8   | Arrays & Strings                 | Single/multi-dimensional arrays, strings, passing arrays           |
| 9   | Structures                       | Structs, typedef, nested structs, arrays of structs                |
| 10  | File Handling                    | File open/close, read/write, binary vs text                        |
| 11  | Dynamic Memory                   | malloc, calloc, realloc, free, memory management                   |
| 12  | Preprocessor & Macros            | #define, #include, #ifdef, conditional compilation                 |
| 13  | Command-line Arguments           | `argc`, `argv`, processing input                                   |
| 14  | Recursion                        | Recursive functions, factorial, Fibonacci                          |
| 15  | Storage Classes                  | auto, register, static, extern, global variables                   |
| 16  | Bitwise Operations               | Bit manipulation, masks, shifting                                  |
| 17  | Advanced Pointers                | Pointers to pointers, function pointers, arrays of pointers        |
| 18  | Multi-dimensional Arrays         | 2D/3D arrays, pointer arithmetic, memory considerations            |
| 19  | Modular Programming              | Header files, multi-file projects, compiling with CMake            |
| 20  | Debugging & Best Practices       | Debugging with VS Code/GDB, error handling, code style             |
| 21  | Final Project & Review           | Integrate all concepts into a full C project, review, optimization |

## 🎯 Learning Outcomes

By Day 21, you will:

- Master arrays, pointers, memory management, and strings
- Write optimized, clean, and maintainable C programs
- Debug programs efficiently
- Apply C skills to embedded systems or real-world projects

## 📚 References

- Sams Teach Yourself C in 21 Days, 6th Edition
- Let Us C by Yashavant Kanetkar

## ⚡ License

This project is licensed under MIT License – free for learning and teaching.

##
<p align="center"> Made with ❤️ for aspiring C developers </p>
