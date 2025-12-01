Below is a fully original, detailed explanation of **Day 13: Advanced Program Control** based on the *topics* requested, **not** on any copied text from the book. All writing is in my own words and follows the structure the book typically uses.

---

# **Day 13: Advanced Program Control**

This lesson explores several tools C gives you for influencing the path your program takes while running. You already know how loops and conditional statements work; now you’ll learn how to *interrupt* loops, *jump* inside a function, *repeat indefinitely*, *select among many choices*, *end a program immediately*, and even *run operating-system commands*.

---

# **1. Ending Loops Early**

Sometimes your loop has a clear ending condition, but real-world situations are messier—maybe you want to stop the loop as soon as a value is found or a certain event occurs. The `break` statement lets you leave a loop instantly.

## **1.1 How `break` Works**

`break` immediately terminates the innermost loop (or `switch`) that contains it. Control transfers to the first statement after that loop.

### **General diagram**

```
+------------+
| Loop Start |
+------------+
       |
       v
+---------------------+
| Condition / Work    |
+---------------------+
       |
       | if (something)
       |      |
       |      v
       |   +--------+
       |   | break; |
       |   +--------+
       |      |
       +------+
              |
              v
   +-----------------------+
   | After the loop ends   |
   +-----------------------+
```

## **1.2 `break` in `for` Loops**

```c
for (int i = 0; i < 10; i++) {
    printf("i = %d\n", i);
    if (i == 4) {          // stop after reaching 4
        break;             // immediate exit
    }
}
printf("Loop ended\n");
```

## **1.3 `break` in `while` Loops**

```c
int x = 0;
while (x < 100) {
    if (x == 10) {
        break;            // terminate early
    }
    printf("%d ", x);
    x++;
}
```

## **1.4 `break` in `do-while` Loops**

```c
int n = 1;
do {
    if (n % 7 == 0) {      // first multiple of 7
        break;
    }
    printf("%d ", n);
    n++;
} while (n < 50);
```

## **1.5 Practical Use Cases**

* Stop searching when the target is found.
* Abort a long calculation under unexpected conditions.
* Terminate user input when a sentinel value is entered.

---

# **2. The `goto` Statement**

`goto` lets you jump directly to a labeled part of your function. It is simple but powerful—and often misused.

## **2.1 Syntax**

```c
goto label;
/* other stuff */
label: printf("Jumped here\n");
```

A label is an identifier followed by a colon placed at the start of a statement.

## **2.2 Simple Example**

```c
int value = 3;

if (value == 3) {
    goto special_case;      // jump down
}

printf("Normal flow\n");

special_case:
printf("Handling special case\n");
```

## **2.3 Why `goto` Is Discouraged**

`goto` can make code hard to follow (“spaghetti code”), especially when jumping backward or when used excessively.

## **2.4 When `goto` Is Useful**

* **Error cleanup** in functions that allocate resources.
* Exiting deeply nested logic without duplicating cleanup code.

Example (resource cleanup):

```c
FILE *fp = fopen("data.txt", "r");
if (!fp) goto error;

char *buffer = malloc(100);
if (!buffer) goto cleanup_fp;

/* ... normal processing ... */

free(buffer);
fclose(fp);
return 0;

cleanup_fp:
fclose(fp);
error:
return 1;
```

---

# **3. Infinite Loops**

An infinite loop runs forever—or until something inside breaks it.

## **3.1 What Is an Infinite Loop?**

A loop with a condition that is always true or with no condition at all.

### **Accidental infinite loop example**

```c
while (i < 10) {  // i never increases!
    printf("Oops\n");
}
```

### **Intentional infinite loop example**

```c
while (1) {       // always true
    /* repeatedly check sensors */
}
```

## **3.2 Creating Infinite Loops**

### Using `for`

```c
for (;;) {
    /* endless loop */
}
```

### Using `while`

```c
while (1) {
    /* do work */
}
```

### Using `do-while`

```c
do {
    /* work */
} while (1);
```

## **3.3 Safely Exiting Infinite Loops**

Use `break` or internal checks:

```c
while (1) {
    int x;
    scanf("%d", &x);
    if (x == 0) break;   // sentinel value
}
```

---

# **4. The `switch` Statement**

`switch` is useful when you want to pick one of many possible actions based on an integer or character expression.

## **4.1 Syntax**

```c
switch (choice) {
    case 1:
        printf("Option 1\n");
        break;
    case 2:
        printf("Option 2\n");
        break;
    default:
        printf("Invalid choice\n");
}
```

* **`case` labels** must be constant integer expressions.
* **`break`** prevents “fall-through” into the next case.
* **`default`** runs when no other case matches.

## **4.2 ASCII Flow Diagram**

```
              +----------------------+
              |    switch(value)     |
              +----------+-----------+
                         |
      -------------------------------------------------
      |                  |                 |         |
      v                  v                 v         v
+-----------+    +-------------+    +-------------+ +--------+
| case 1    |    | case 2      |    | case 3      | | default|
+-----------+    +-------------+    +-------------+ +--------+
      |                  |                 |          |
   break              break             break       (optional)
      |__________________|_________________|__________|
                         |
                         v
              +-------------------------+
              |  Continue after switch  |
              +-------------------------+
```

---

# **5. Exiting the Program**

To end a program immediately—regardless of where you are—you can use `exit()` from `<stdlib.h>`.

## **5.1 Syntax**

```c
#include <stdlib.h>
exit(0);      // normal termination
```

## **5.2 Exit Codes**

| Exit Code | Meaning                       |
| --------- | ----------------------------- |
| `0`       | Program finished normally     |
| Nonzero   | Error or abnormal termination |

Example:

```c
if (fp == NULL) {
    fprintf(stderr, "Failed to open file\n");
    exit(1);    // report error
}
```

---

# **6. Executing OS Commands**

C programs can run shell commands using the `system()` function.

## **6.1 Syntax**

```c
#include <stdlib.h>
system("command");
```

## **6.2 Examples**

```c
system("dir"); // Windows
system("ls");  // Linux or macOS
```

## **6.3 Portability and Security**

* Commands differ between operating systems.
* Avoid using untrusted strings with `system()`—it can execute arbitrary code.
* Prefer direct C library calls when possible.

---

# **7. Practice Exercise**

Write a program that presents a simple menu, uses a loop with `break`, applies a `switch`, and optionally executes an OS command.

## **Example Program**

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int choice;

    while (1) {
        printf("\n=== Menu ===\n");
        printf("1. Say Hello\n");
        printf("2. List Directory\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Hello there!\n");
                break;

            case 2:
                printf("Directory listing:\n");
                system("ls");   // or "dir" on Windows
                break;

            case 3:
                printf("Exiting...\n");
                break;          // exit switch first
            default:
                printf("Invalid selection.\n");
                continue;       // return to top of loop
        }

        if (choice == 3) {
            break;              // exit loop entirely
        }
    }

    printf("Program ended.\n");
    return 0;
}
```

## **Expected Output (example)**

```
=== Menu ===
1. Say Hello
2. List Directory
3. Quit
Enter choice: 1
Hello there!

=== Menu ===
...
```

## **Flow Diagram**

```
 +----------------+
 | Start Program  |
 +-------+--------+
         |
         v
 +----------------+
 |   Menu Loop    |
 +--------+-------+
          |
          v
  +------------------+
  | Read user choice |
  +---+--------------+
      |
      v
 +------------ switch ----------------+
 |                                     |
 |      +--------+   +---------+      |
 |      | 1:Hello|   | 2:List  |      |
 |      +--------+   +---------+      |
 |             \       /              |
 |              \     /               |
 |          +--------------+          |
 |          | 3: Quit      |          |
 |          +--------------+          |
 +-----------------+------------------+
                   |
              if choice==3
                   |
                   v
        +-----------------------+
        | Break from loop       |
        +-----------------------+
                   |
                   v
         +------------------------+
         | End of Program         |
         +------------------------+
```

---

# **Summary of Key Points**

* **`break`** allows early termination of loops and prevents fall-through in `switch`.
* **`goto`** jumps to a labeled statement; useful mainly for cleanup.
* **Infinite loops** can be useful but require safe exit techniques.
* **`switch`** is ideal for multi-branch decisions.
* **`exit()`** stops the program immediately and returns a code.
* **`system()`** executes OS commands but has portability and security limitations.

Using these tools, you can build C programs with much more sophisticated control over how execution flows—whether looping, branching, or terminating early.

---
