# C Development Environment Setup (Windows)  
Complete Guide — MinGW-w64 + VS Code + CMake

This document explains how to set up a modern C development environment on Windows using:

- **MinGW-w64** (GCC compiler)
- **Visual Studio Code**
- **CMake** (optional, recommended for projects)
  
This setup is ideal for beginners starting their C learning journey (e.g., “Learn C in 21 Days”).

---

# 📦 1. Install MinGW-w64 (GCC Compiler)

⚠️ Avoid the old “MinGW”.  
Use **WinLibs MinGW-w64**, which is up-to-date and works well with VS Code & CMake.

### ✅ Steps:

1. Download WinLibs MinGW-w64 (GCC)  
2. Extract to a safe location, e.g.:  C:\mingw64
3. Add MinGW to your system PATH:
  - Press **Win+S** → type **Environment Variables**
  - Open **Environment Variables**
  - Under *User variables*, select **Path** → **Edit**
  - Add:
  ```
  C:\mingw64\bin
  ```

4. Confirm installation by opening a new Terminal / PowerShell:

  ```bash
  gcc --version
  g++ --version
  gdb --version

# 🧰 2. Install Visual Studio Code

Download:
VS Code (free)

Install with default options.

Recommended Extensions:

C/C++ (Microsoft)

C/C++ Extension Pack (optional)

CMake Tools (recommended)

CMake (optional)

#  📐 3. Install CMake (Optional but Recommended)

If you plan to build multi-file C projects:

Download CMake

During setup, choose:
✔ Add CMake to PATH for all users

Verify installation:

cmake --version
🧪 4. Test C Compiler (Hello World)

Create a new file hello.c:

#include <stdio.h>

int main() {
    printf("Hello, World!\\n");
    return 0;
}


Compile:

gcc hello.c -o hello.exe


Run:

./hello.exe


You should see:

Hello, World!

# 📁 5. (Optional) Basic CMake Project Setup

Create a folder structure:

project/
 ├── CMakeLists.txt
 └── main.c

CMakeLists.txt:
cmake_minimum_required(VERSION 3.15)
project(MyCProject C)

set(CMAKE_C_STANDARD 11)

add_executable(myapp main.c)

main.c:
#include <stdio.h>

int main() {
    printf("Hello from CMake!\\n");
    return 0;
}

Build using CMake + MinGW:
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build


Run:

./build/myapp.exe

✔ Setup Completed

You now have:

MinGW-w64 GCC Compiler

VS Code configured for C

(Optional) CMake build system

A working test program

You're ready to begin your C learning roadmap.

# 📚 Next Step: Learn C in 21 Days

This repository will later include:

Daily C learning modules

Example programs

Practice exercises

Mini-projects

Advanced C topics

Stay tuned!
