# Day 01 – Introduction to C & Environment Setup

## 🎯 Objective

By the end of Day 01, you will:

- Understand the history and significance of the C programming language.  
- Set up your development environment with MinGW, CMake, and VS Code.  
- Write, compile, and execute your first C programs with clear line-by-line understanding.  

---

## 📖 Description

### Basic Structure of a C Program

A minimal C program looks like this:

```c
#include <stdio.h>   // Include standard input/output library

int main() {         // main() is the entry point of the program
    printf("Hello, World!\n");  // Print text to the console
    return 0;        // Return 0 indicates the program finished successfully
}
```
### Explanation:

-  **#include <stdio.h>**
   * Brings in the Standard Input/Output library so you can use printf, scanf, etc.

- **int main()**
   * The main function where execution starts. It must return an integer (int).

- **printf("…");-**
   * Prints text to the console.

- **return 0;-**
  * Signals successful execution to the operating system.

## 💻 Examples Walkthrough (with comments)

### 1️⃣ Example 1 – Hello World
  ```c
  #include <stdio.h>   // Include standard input/output functions

  int main()  // main() function – entry point of the program 
  {         
      printf("Hello, C World!\n");  // Print message to the console
      return 0;        // Exit program successfully
  }
  ```
#### Expected Output:
  ```c
  Hello, C World!
  ```
### 2️⃣ Example 2 – Simple Addition
  ```c
  #include <stdio.h>   // Include standard input/output functions

  int main() 
  {
      int a, b;                     // Declare two integer variables
      printf("Enter two numbers: "); // Prompt the user for input
      scanf("%d %d", &a, &b);        // Read two integers from user and store in a and b
      printf("Sum = %d\n", a + b);   // Calculate sum and print it
      return 0;                       // Exit program successfully
  }
  ```
### Sample Run:
  ```c
  Enter two numbers: 5 7
  Sum = 12
  ```
### 3️⃣ Example 3 – Using Variables and Constants
  ```c
  #include <stdio.h>          // Include standard input/output functions

  int main() {
      const float PI = 3.14159;   // Define a constant for pi
      float radius, area;          // Declare variables for radius and area

      printf("Enter radius of circle: ");  // Prompt user for radius
      scanf("%f", &radius);                // Read radius input

      area = PI * radius * radius;         // Calculate area of circle
      printf("Area of the circle: %.2f\n", area); // Print area rounded to 2 decimals

      return 0;  // Exit program successfully
  }
  ```
### Sample Run:
  ```c
  Enter radius of circle: 2.5
  Area of the circle: 19.63
  ```
### Notes:
- Constants (const) cannot be changed during program execution.
- %f is used for float variables, and %.2f limits output to 2 decimal places.


## Best Practices

- Comment every line or block of code while learning.
- Use meaningful variable names and consistent indentation.
- Test programs with different inputs.
- Organize examples in the examples/ folder.