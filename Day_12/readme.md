Below is an **original, re-written, tutor-friendly explanation** following the structure of *Day 12: Understanding Variable Scope* from **Sams Teach Yourself C in 21 Days (6th Ed.)**, without copying from the book.

---

# **Day 12: Understanding Variable Scope**

Variable **scope** tells you *where* in a program a variable can be used and *how long* it continues to exist in memory. Managing scope is essential for writing predictable, maintainable C programs.

---

# **1. What Is Scope?**

In C, **scope** means *the region of a program where a variable name is valid and can be accessed*.
C has two major categories of scope:

* **Local scope** — variables declared inside functions or blocks
* **Global scope** — variables declared outside all functions

When the compiler reads your program, it determines which variables are visible in each part of the code.

### **ASCII Visibility Diagram**

```
+---------------------------------------------+
| Global Scope                                |
| int g = 10;                                 |
+-----------------------+---------------------+
                        |
                        v
                +---------------+
                | main()        |
                | int a = 5;    |  <-- local to main
                |               |
                |   {           |
                |     int b=7;  |  <-- local to block
                |   }           |
                +---------------+
```

---

# **2. External Variables (Global Variables)**

A variable placed **outside all functions** is a *global variable*. It becomes visible from the point of declaration until the end of the file.

```c
int globalVar = 10;   // accessible to all functions in this file
```

### **Advantages**

* **Shared state:** Multiple functions can read or modify the same data.
* **Long lifetime:** They exist for the entire run of the program.
* **Convenient:** Helpful when many functions require access to the same value.

### **Risks**

* **Harder to track:** Any function can change them.
* **Namespace pollution:** Too many globals make programs complicated.
* **Debugging difficulty:** Bugs may come from unexpected modifications.

Global variables should be used sparingly and intentionally.

---

# **3. Local Variables**

A **local variable** is declared inside a function or block and is visible *only within that region*. When execution leaves the function, the variable disappears.

```c
void demo() {
    int x = 3;   // local: only exists while demo() is running
    printf("%d\n", x);
}
```

Local variables:

* Live only during the function call
* Are stored on the stack
* Are re-created every time the function runs
* Do not affect identically-named variables elsewhere

---

# **4. Local Variables in `main()`**

`main()` is just another function, so its variables are **local**, not global.

```c
int num = 20;      // global

int main() {
    int num = 5;   // local variable shadows the global
    printf("%d\n", num);   // prints 5 (local wins)
    return 0;
}
```

### **Shadowing**

If a local variable uses the same name as a global, the local one temporarily *hides* the global within that scope.

ASCII summary:

```
global num = 20
       |
       +--> main(): int num = 5   // global num hidden here
```

To access the hidden global, you would need separate functions or redesign—not something C provides direct syntax for inside the same function.

---

# **5. Storage Classes**

Storage classes specify **how long variables exist** and **how they are stored**.

### **Main Storage Classes in C**

| Storage Class | Scope        | Lifetime       | Default Value |
| ------------- | ------------ | -------------- | ------------- |
| `auto`        | local        | function call  | garbage       |
| `register`    | local        | function call  | garbage       |
| `static`      | local/global | entire program | 0             |
| `extern`      | global       | entire program | depends       |

### **Quick Notes**

* `auto`

  * Default for local variables

* `register`

  * Suggests storing a frequently used variable in a CPU register

* `static` (local)

  * Keeps its value between function calls

* `static` (global)

  * Limits visibility to the current file

* `extern`

  * Tells the compiler a variable exists in another file

---

# **6. Local Variables and Blocks**

A **block**—anything inside `{ }`—creates a *new* scope.
Variables declared inside a block:

* Exist only within that block
* Can hide variables with the same name from outer scopes

Example:

```c
int main() {
    int x = 1;
    printf("Outer x = %d\n", x);

    {
        int x = 2;   // hides outer x
        printf("Inner x = %d\n", x);
    }

    printf("Outer x again = %d\n", x);
}
```

Output:

```
Outer x = 1
Inner x = 2
Outer x again = 1
```

---

# **7. Practice Exercise: Type & Run 4**

This example demonstrates:

* A global variable
* Local variables
* Shadowing
* A function accessing globals

---

## **Program Example**

```c
#include <stdio.h>

int globalCount = 100;   // global variable

void showValues(int localParam) {
    printf("Inside showValues():\n");
    printf("  globalCount = %d\n", globalCount);  // access global
    printf("  localParam  = %d\n\n", localParam); // function parameter
}

int main() {
    int globalCount = 5;  // local variable shadows global
    int mainLocal = 20;   // local to main

    printf("Inside main():\n");
    printf("  globalCount (local) = %d\n", globalCount);
    printf("  mainLocal           = %d\n\n", mainLocal);

    showValues(mainLocal);  // call function, passing local

    return 0;
}
```

### **Expected Output**

```
Inside main():
  globalCount (local) = 5
  mainLocal           = 20

Inside showValues():
  globalCount = 100
  localParam  = 20
```

### **ASCII Lifetime Diagram**

```
Program Start
+--------------------------------------------------+
| Global: globalCount = 100 (exists entire program)|
+-------------------------+------------------------+
                          |
                          v
                    Call main()
                    +-----------------------------+
                    | local globalCount = 5       |
                    | mainLocal = 20              |
                    +-----------------------------+
                          |
                          v
                   Call showValues()
                   +-----------------------------+
                   | localParam = 20             |
                   | (globalCount = 100 visible) |
                   +-----------------------------+
```

---

# **Summary of Key Points**

* **Scope** determines where a variable name is valid.
* **Local variables** exist only in functions or blocks and are recreated each call.
* **Global variables** live for the program’s lifetime and are accessible by all functions after their declaration.
* **Shadowing** happens when a local variable uses the same name as a global.
* **Storage classes** (`auto`, `register`, `static`, `extern`) influence how long variables live and their visibility.
* Proper use of scope leads to clearer, safer, more maintainable programs.

If you'd like, I can also generate **quiz questions**, **memory diagrams**, or **practice problems** for this lesson!
