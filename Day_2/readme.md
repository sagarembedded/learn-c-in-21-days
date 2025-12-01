Below is an **original, instructional explanation** of “**Day 2: The Components of a C Program**,” written in my own words, following the structure of *Sams Teach Yourself C in 21 Days, 6th Edition* but **without copying** from the book.

---

# **Day 2 – The Components of a C Program**

Understanding how a C program is organized is essential before you start writing longer and more complex code. Today we’ll break a C program into recognizable parts and discuss what each part does.

---

# **1. A Short C Program**

Let’s begin with a tiny example program that prints a message and performs simple arithmetic.

```c
#include <stdio.h>      // Gives access to printf() and other I/O functions

int main(void)          // The starting point of every C program
{
    int a = 5;          // Declare variable 'a' and initialize it with 5
    int b = 3;          // Declare variable 'b' and initialize it with 3
    int sum = a + b;    // Compute an expression and store the result in 'sum'

    printf("The sum is %d\n", sum);  // Display the value of 'sum'

    return 0;           // Signal that the program ended successfully
}
```

This small program contains most of the essential building blocks you’ll encounter in C.

---

# **2. The Program’s Components**

Every C program consists of several key elements. Understanding these early will make later concepts easier.

---

## **Preprocessor Directives**

Preprocessor directives are instructions that run *before* the compiler processes the code. They typically begin with a `#` character.

* `#include <stdio.h>` inserts the declarations needed for input/output functions like `printf()`.
* Other directives include `#define` (for constants/macros) and `#ifdef` (for conditional compilation).

These lines are not C statements—no semicolon is used.

---

## **Functions**

Functions are self-contained pieces of code that perform specific tasks.

* **`main()`** is the required function where program execution begins.
* You can define additional functions for organizing logic into reusable chunks.
* Each function has:

  * A return type (e.g., `int`)
  * A name (e.g., `main`)
  * A parameter list (even if empty, use `void`)
  * A body containing statements inside `{ }`

---

## **Statements and Expressions**

### **Statements**

A C statement tells the program to do something and ends with a semicolon:

```c
sum = a + b;
printf("Hello\n");
```

### **Expressions**

Expressions are combinations of values, variables, and operators that produce a result:

```c
a + b
x * 10
n > 0
```

Statements often *contain* expressions.

---

## **Variables and Constants**

### **Variables**

Variables represent storage locations in memory:

```c
int count;
char letter;
float price;
```

They must be declared before use.

### **Constants**

Constants are fixed values that do not change during program execution:

```c
#define PI 3.14159     // Preprocessor constant
const int LIMIT = 100; // Typed constant
```

---

## **Comments**

Comments explain code for human readers and are ignored by the compiler.

Two styles exist:

```c
// Single-line comment

/* Multi-line
   comment */
```

Use comments to explain purpose—not obvious details.

---

## **Summary Table: Program Components**

| Component                  | Example              | Purpose                                                    |
| -------------------------- | -------------------- | ---------------------------------------------------------- |
| **Preprocessor Directive** | `#include <stdio.h>` | Include external declarations or macros before compilation |
| **Function**               | `int main(void)`     | Contains executable code; `main()` is the starting point   |
| **Statement**              | `sum = a + b;`       | Performs an action; ends with semicolon                    |
| **Expression**             | `a + b`              | Produces a value using operations                          |
| **Variable**               | `int x = 10;`        | Stores a modifiable value                                  |
| **Constant**               | `#define MAX 10`     | Represents a fixed value                                   |
| **Comment**                | `/* note */`         | Documents code for humans                                  |

---

# **3. Review of How the Parts Fit Together**

A C program always follows a general “top-to-bottom” structure:

1. **Preprocessor directives** appear at the top and prepare required libraries or constants.
2. **Function definitions** follow. Every program must have at least one function: `main()`.
3. Inside **main()**, you write statements and expressions that perform your desired tasks.
4. Variables hold data; constants provide fixed values used in calculations.
5. Comments document how the code works.

---

## **ASCII Diagram of Program Structure**

```
+----------------------------+
|  Preprocessor Directives   |
+----------------------------+
                |
                v
+----------------------------+
|     Function Definitions    |
+----------------------------+
                |
                v
+----------------------------+
|        main() Function      |
|  - Variable declarations    |
|  - Statements               |
|  - Expressions              |
+----------------------------+
                |
                v
          Program Output
```

---

# **4. Practice Exercise – Type & Run**

Below is a small program using all components discussed today. Try typing it yourself and running it.

---

## **Program: Calculate Area of a Rectangle**

```c
#include <stdio.h>          // Provides printf()

#define LABEL "Rectangle Area Calculator"  // Preprocessor constant

int main(void)
{
    int width = 8;          // Variable declaration and initialization
    int height = 5;         // Another variable

    int area = width * height;  // Expression inside a statement

    // Display the result to the user
    printf("%s\n", LABEL);
    printf("Width = %d\n", width);
    printf("Height = %d\n", height);
    printf("Area = %d\n", area);

    return 0;               // Indicate successful completion
}
```

### **Expected Output**

```
Rectangle Area Calculator
Width = 8
Height = 5
Area = 40
```

---

# **Key Takeaways**

* A C program is built from **preprocessor directives**, **functions**, **statements**, **expressions**, **variables**, **constants**, and **comments**.
* The `main()` function is the mandatory entry point.
* Statements perform actions; expressions compute values.
* Comments help humans understand the code but are ignored by the compiler.
* Understanding these components gives you the foundation for writing more complex programs later.

---
