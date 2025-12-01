Below is a fully original, tutor-style explanation of **Day 7: Fundamentals of Reading and Writing Information** based on the *topics* you listed. No wording is taken from the book, but the structure and subject coverage reflect what is commonly taught in this chapter.

---

# **Day 7 — Fundamentals of Reading and Writing Information**

C programs become useful only when they interact with people or other systems—usually by *reading* information in and *writing* information out. Day 7 focuses on these two actions: sending output to the screen and collecting input from the keyboard. It also introduces trigraphs, a historical feature of C.

---

# **1. Displaying Information On-Screen**

## **1.1 How `printf()` Works**

`printf()` is one of the most important standard library functions in C. It sends formatted text to the screen. The word “formatted” is key: you supply a string that may contain normal characters (letters, digits, punctuation) *and* special placeholders called **format specifiers**. These placeholders tell `printf()` how to display different kinds of data.

**Basic example:**

```c
printf("Hello, world!\n");          // prints a simple message
```

**With a placeholder:**

```c
int age = 25;
printf("Age: %d\n", age);           // %d is replaced by the value of 'age'
```

## **1.2 Placeholders for Different Data Types**

Format specifiers begin with `%` and are followed by a letter indicating the data type.

### **Common examples**

```c
int count = 7;
float price = 12.50;
char grade = 'A';
char name[] = "Alice";

printf("Count = %d\n", count);      // integer
printf("Price = %f\n", price);      // floating-point
printf("Grade = %c\n", grade);      // character
printf("Name  = %s\n", name);       // string
```

## **1.3 Formatting Output: Width, Precision, and Alignment**

Format specifiers can include optional settings to control how the value appears.

### **Width**

Specifies the minimum number of characters to use:

```c
printf("%10d\n", 42);   // right-aligned in a 10-character field
```

### **Precision**

Controls digits after the decimal for floats:

```c
printf("%.2f\n", 3.14159);   // prints 3.14
```

### **Width + Precision**

Combine them:

```c
printf("%8.3f\n", 3.14159);  // field width 8, 3 digits after decimal
```

### **Left Alignment**

Place a minus sign before the width:

```c
printf("%-10dEND\n", 42);    // left-aligned
```

---

## **1.4 Format Specifier Summary**

| Specifier | Data Type | Example              |
| --------- | --------- | -------------------- |
| %d        | int       | `printf("%d", x);`   |
| %f        | float     | `printf("%.2f", y);` |
| %c        | char      | `printf("%c", ch);`  |
| %s        | string    | `printf("%s", str);` |

---

# **2. Inputting Numeric Data with `scanf()`**

## **2.1 What `scanf()` Does**

`scanf()` reads information typed by the user and stores it into variables. You tell it what format to expect using format specifiers similar to `printf()`.

## **2.2 Why `&` Is Required**

`scanf()` must know *where* in memory to store input. The `&` operator gives the **address** of a variable.
Strings (arrays of `char`) are an exception because the variable name already represents an address.

## **2.3 Examples**

### **Read an integer**

```c
int age;
printf("Enter your age: ");
scanf("%d", &age);               // &age provides the memory address
```

### **Read a floating-point number**

```c
float temperature;
printf("Enter temperature: ");
scanf("%f", &temperature);       // %f for float
```

### **Read a single character**

```c
char answer;
printf("Continue? (y/n): ");
scanf(" %c", &answer);           // leading space avoids leftover newline
```

### **Inline explanation example**

```c
int x;
float y;

printf("Enter an integer and a float: ");
scanf("%d %f", &x, &y);
/* %d   -> expects an integer
   %f   -> expects a float
   &x   -> address of x for storing the integer
   &y   -> address of y for storing the float */
```

---

# **3. Using Trigraph Sequences**

## **3.1 What Are Trigraphs?**

Before keyboards were standardized, some characters used in C source code were difficult or impossible to type. Trigraphs were introduced to allow certain characters to be written using a 3-character sequence beginning with `??`.

Example:

* `??=` represents `#`
* `??/` represents `\`
* `??)` represents `]`

## **3.2 Why They Matter**

Modern systems virtually never need trigraphs, and many developers disable them to avoid confusion. However, you may encounter trigraphs in old codebases or in environments where certain symbols aren’t available.

## **3.3 Examples**

```c
// Using trigraphs:
??=include <stdio.h>       // same as #include <stdio.h>
printf("Path: C:??/folder");  // prints: C:\folder
```

Again, these are rare today, but understanding them can help when reading legacy C programs.

---

# **4. Practice Exercise**

Here is a small program that reads user input and displays formatted output.

---

## **4.1 Practice Program**

```c
#include <stdio.h>

int main(void)
{
    int quantity;
    float price;

    // Ask the user for input
    printf("Enter quantity: ");
    scanf("%d", &quantity);       // read integer

    printf("Enter price per item: ");
    scanf("%f", &price);          // read float

    float total = quantity * price;

    // Display formatted output
    printf("\n--- Receipt ---\n");
    printf("Quantity: %d\n", quantity);
    printf("Unit Price: $%.2f\n", price);     // format to 2 decimal places
    printf("Total:     $%.2f\n", total);

    return 0;
}
```

### **Expected Output**

```
Enter quantity: 3
Enter price per item: 19.95

--- Receipt ---
Quantity: 3
Unit Price: $19.95
Total:     $59.85
```

---

## **4.2 ASCII Flow Diagram**

```
 +----------------+       +-------------------+       +------------------+
 |  User Input    | --->  |  Program Reads    | --->  |  Formatted Output |
 | (keyboard)     |       | (scanf processes) |       |    (printf)       |
 +----------------+       +-------------------+       +------------------+
```

---

# **Summary of Key Points**

* **`printf()`** displays information using format specifiers to control layout, alignment, and precision.
* **`scanf()`** reads data typed by the user; the **`&` operator is required** so the function knows where to store the input.
* **Trigraph sequences** are an outdated way to represent characters that were once difficult to type; rarely needed today but useful to recognize.
* Understanding fundamental input/output functions is essential for writing interactive C programs.

If you'd like, I can also create **practice quizzes**, **additional exercises**, or a **cheat sheet** for Day 7.
