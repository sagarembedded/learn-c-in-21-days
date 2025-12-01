Below is a **fully original explanation**, written in my own words, following the requested structure and topics from *Day 3: Storing Information: Variables and Constants* of **Sams Teach Yourself C in 21 Days, 6th Edition**, without copying the book's text.

---

# **Day 3 — Storing Information: Variables and Constants**

Programming is all about working with information—collecting it, processing it, and producing useful results. In C, this information lives in memory, and we interact with it through **variables** and **constants**. Today’s lesson covers how memory works, how you store values in variables, how numeric types differ, and how constants make your programs safer and easier to read.

---

# 1. **Understanding Your Computer’s Memory**

### **Memory as a Collection of Numbered Slots**

A computer’s memory can be imagined as a long row of small storage boxes.
Each box holds a **byte** (8 bits), and each box has a unique **address**—similar to house numbers on a street.

```
Address:   1000  1001  1002  1003  1004  1005
Contents:  ----  ----  ----  ----  ----  ----
```

When your program creates a variable, the compiler chooses one or more of these boxes to store its value.

---

### **Data Types Occupy Different Amounts of Memory**

Because different types of values require different precision, C defines several **data types**, each needing a specific number of bytes. For example:

* `char` → usually uses **1 byte**
* `int` → typically **4 bytes**
* `double` → usually **8 bytes**

Here’s an ASCII diagram showing how a single `int` variable (4 bytes) might be stored:

```
Variable: int score = 75;

Memory:
Address:    2000   2001   2002   2003
Contents:   4B     00     00     00     <-- example internal representation
```

C doesn’t require you to manage these addresses manually, but understanding them helps you see why choosing the right type matters.

---

# 2. **Storing Information with Variables**

### **What Is a Variable?**

A **variable** is a named location in memory that can store a value.
You can retrieve the value later, change it, or use it in calculations.

### **Declaring and Initializing Variables**

To tell C that you want to use a variable, you **declare** it by specifying its type and name:

```c
int age;         // declaration
age = 20;        // assignment
```

You may also declare and assign a value at the same time, known as **initialization**:

```c
int age = 20;
float price = 9.99;
char grade = 'A';
```

---

### **Rules for Variable Names (Identifiers)**

C has specific rules for naming variables:

* Must begin with a **letter** or **underscore** (not a digit).
* Remaining characters can be **letters, digits, or underscores**.
* C is **case-sensitive**: `Age` and `age` are two different variables.
* Cannot use **keywords** such as `int`, `return`, `while`, etc.
* Avoid spaces or punctuation.

Examples of valid identifiers:

* `total`
* `number_of_items`
* `_temp`

Examples of invalid identifiers:

* `3dogs` (starts with a digit)
* `first-name` (illegal character `-`)
* `float` (keyword)

---

# 3. **Numeric Variable Types**

C provides several built-in numeric types. These types define:

* How much memory the variable uses
* What range of values it can represent
* How much precision it offers for floating-point numbers

> **Note:** Sizes shown below reflect “typical” modern systems, but they can vary by compiler or architecture.

---

## **Common Numeric Types**

| Type   | Size (typical) | Range (approx.)                            | Example               |
| ------ | -------------- | ------------------------------------------ | --------------------- |
| int    | 4 bytes        | −2,147,483,648 to 2,147,483,647            | `int x = 10;`         |
| float  | 4 bytes        | ±3.4e−38 to ±3.4e38 (≈6 decimal digits)    | `float y = 3.14;`     |
| double | 8 bytes        | ±1.7e−308 to ±1.7e308 (≈15 decimal digits) | `double z = 3.14159;` |

---

## **Type Modifiers**

Modifiers allow you to refine the meaning of a base type:

### **signed / unsigned**

* `signed` numbers can be positive or negative.
* `unsigned` numbers represent **only non-negative** values, doubling the positive range.

Example:

```c
unsigned int count = 50;    // cannot be negative
```

### **short / long**

Adjusts the storage size for integers:

```c
short s;         // often 2 bytes
long bigValue;   // often 8 bytes
long long huge;  // even larger range
```

Modifiers can be combined:

```c
unsigned long counter;
```

Use the smallest type that accurately covers your range; it keeps memory usage efficient and helps avoid overflow.

---

# 4. **Constants**

### **What Is a Constant?**

A **constant** is a value that **cannot change while the program runs**.
Constants improve safety by preventing accidental modification and make code more readable.

---

## **Defining Constants**

### **Using the `const` Keyword**

```c
const int DAYS_IN_WEEK = 7;
```

* Treated like a variable but read-only.
* Checked by the compiler; modifying it causes an error.

### **Using `#define` Macros**

```c
#define PI 3.14159
```

* Handled by the **preprocessor**, replacing occurrences of the name before compilation.
* Does not occupy storage like a variable.

---

## **`const` vs. `#define`**

| Feature         | `const`             | `#define`                   |
| --------------- | ------------------- | --------------------------- |
| Type-checked?   | Yes                 | No                          |
| Uses memory?    | Yes (as a variable) | No (text substitution only) |
| Debug-friendly? | Yes                 | Less so                     |

Use `const` when you want a typed constant, and `#define` when you want a symbolic replacement.

---

# 5. **Practice Exercise**

Write a short program that declares different variables, initializes them, and prints their values.

### **Exercise Code**

```c
#include <stdio.h>

int main(void) {
    int age = 25;                 // integer variable
    float price = 19.95;          // floating-point variable
    const int DAYS = 7;           // constant using const
    #define PI 3.14159            // constant using #define
    char grade = 'A';             // character variable

    printf("Age: %d\n", age);
    printf("Price: %.2f\n", price);
    printf("Days in a week: %d\n", DAYS);
    printf("Pi constant: %f\n", PI);
    printf("Grade: %c\n", grade);

    return 0;
}
```

### **Expected Output**

```
Age: 25
Price: 19.95
Days in a week: 7
Pi constant: 3.141590
Grade: A
```

---

# **Summary of Key Points**

* Memory is a series of numbered byte-sized locations; variables occupy one or more of these locations.
* A variable is a named storage area whose value can change during program execution.
* C provides several numeric types (`int`, `float`, `double`, etc.), each with different sizes and value ranges.
* Type modifiers (`unsigned`, `short`, `long`) allow finer control of numeric storage.
* Constants store fixed values; `const` and `#define` are the two main ways to create them.
* Knowing how types and memory relate helps you write efficient, reliable C programs.

---

