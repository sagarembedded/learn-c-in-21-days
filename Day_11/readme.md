# **Day 11: Implementing Structures, Unions, and `typedef`s**

*(A concept-focused, original explanation inspired by the structure of the referenced book—no copied text.)*

---

## **1. Working with Simple Structures**

### **What Is a Structure?**

A **structure** is a custom data type that lets you bundle together several related values—even if they use different primitive types. Instead of keeping associated variables scattered throughout your program, a structure stores them as one coherent unit. This makes your code easier to understand and maintain.

### **Defining a Structure**

Here’s the basic syntax for creating a structure type:

```c
struct Point {
    int x;
    int y;
};
```

* `struct` introduces the new type.
* `Point` becomes the tag (or name) of the structure type.
* `x` and `y` are *members* of the structure.

### **Declaring and Initializing Structure Variables**

Once defined, you can declare structure variables just like built-in types:

```c
struct Point p1;     // declaration
p1.x = 4;            // assignment
p1.y = 9;
```

Or initialize them right away:

```c
struct Point p2 = {4, 9};
```

---

## **2. More Complex Structures**

Structures are not limited to two integers—they can contain many members with various data types.

### **Example: Multiple Member Types**

```c
struct Employee {
    char name[30];
    int id;
    double salary;
};
```

### **Nested Structures (Structure Inside a Structure)**

A structure can also contain other structures, allowing you to model more complex data:

```c
struct Date {
    int day;
    int month;
    int year;
};

struct Person {
    char name[30];
    struct Date birthdate;  // nested structure
};
```

Accessing nested members:

```c
struct Person p;
p.birthdate.day = 12;
p.birthdate.month = 7;
p.birthdate.year = 1995;
```

---

## **3. Arrays of Structures**

You can group many structure variables using an array.

```c
struct Point points[5];  // array of 5 Point structures
```

### **Accessing Members of Array Elements**

```c
points[0].x = 10;
points[0].y = 20;
```

Each array element is itself a structure, so use the dot operator after selecting the element.

---

## **4. Initializing Structures**

### **Initialization at Declaration**

```c
struct Point p1 = {10, 20};
```

You can also partially initialize:

```c
struct Point p2 = {5}; // x = 5, y = 0 (defaulted)
```

Unused members are automatically set to zero (for numeric types) or null characters (for arrays).

---

## **5. Structures and Pointers**

### **Using Pointers with Structures**

```c
struct Point p1 = {3, 7};
struct Point *ptr = &p1;  // ptr points to p1
```

### **Accessing Members via Pointer**

You can dereference the pointer manually:

```c
(*ptr).x = 8;
```

But C provides a cleaner operator for this:

### **The Arrow Operator (`->`)**

```c
printf("%d\n", ptr->x);  // same as (*ptr).x
```

---

## **6. Understanding Unions**

### **What Is a Union?**

A **union** looks similar to a structure, but with one crucial difference:

* **All members share the same memory space.**
* Only one member is valid at a time.

### **Defining a Union**

```c
union Data {
    int i;
    float f;
    char str[20];
};
```

Here, the union reserves enough memory to hold **its largest member** (`char[20]`). All members overlap in that space.

### **Difference from Structures**

| Feature           | Structure                | Union                                        |
| ----------------- | ------------------------ | -------------------------------------------- |
| Memory allocation | Sum of member sizes      | Size of largest member                       |
| Member access     | All valid simultaneously | Only most recently assigned member is valid  |
| Use case          | Group related values     | Store different representations of one value |

---

## **7. Creating Synonyms with `typedef`**

### **What `typedef` Does**

`typedef` lets you create a shorter or more meaningful alias for a type.

```c
typedef struct Point PointType;

PointType p2 = {4, 8};
```

### **Why Use `typedef`?**

* Reduces repetitive typing
* Improves readability
* Makes large programs easier to maintain
* Popular when working with complex types like structures, pointers, and function pointers

---

## **8. Practice Exercise**

Below is a small program tying together structures, arrays, pointers, and functions.

### **Program: Managing Student Records**

```c
#include <stdio.h>

struct Student {
    char name[30];
    int age;
    char grade;
};

/* Function that receives a pointer to a Student and prints its data */
void displayStudent(const struct Student *s) {
    printf("Name : %s\n", s->name);    // using -> with pointer
    printf("Age  : %d\n", s->age);
    printf("Grade: %c\n\n", s->grade);
}

int main() {
    // Array of structure variables
    struct Student class[3] = {
        {"Alice", 20, 'A'},
        {"Bob",   19, 'B'},
        {"Cara",  21, 'A'}
    };

    for (int i = 0; i < 3; i++) {
        displayStudent(&class[i]); // pass pointer to each element
    }

    return 0;
}
```

### **Expected Output**

```
Name : Alice
Age  : 20
Grade: A

Name : Bob
Age  : 19
Grade: B

Name : Cara
Age  : 21
Grade: A
```

---

## **Optional ASCII Diagram: Structure Memory Layout**

For this structure:

```c
struct Student {
    char name[30];
    int age;
    char grade;
};
```

Memory might look like:

```
+------------------------------+
| name[0..29]                  | 30 bytes
+------------------------------+
| age                          | 4 bytes
+------------------------------+
| grade                        | 1 byte
+------------------------------+
           (padding may occur)
```

---

# **Summary of Key Points**

* **Structures** bundle related data of various types into one unit.
* **Nested structures** allow you to build sophisticated representations of real-world items.
* **Arrays of structures** store lists of structured data.
* **Pointers to structures** make functions more efficient and allow the use of the `->` operator.
* **Unions** let multiple members share the same memory location—only one is valid at a time.
* **`typedef`** simplifies type names and improves readability.
* These tools are essential for building larger, cleaner, and more modular C programs.

If you’d like, I can also generate practice problems, quizzes, or diagrams for any subsection!
