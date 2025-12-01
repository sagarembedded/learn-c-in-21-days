Below is a **fully original**, detailed explanation of **Day 19: Exploring the C Function Library**, modeled after the structure of *Sams Teach Yourself C in 21 Days* but written entirely in my own words and **without copying** from the book.

---

# **Day 19 — Exploring the C Function Library**

The C standard library supplies a broad set of ready-made routines that perform common tasks: mathematics, manipulating dates and times, reporting errors, and working with generic searching/sorting functions. Today’s lesson shows how to use these built-in capabilities so you can write cleaner and more efficient programs.

---

# **1. Mathematical Functions (`math.h`)**

The `<math.h>` header contains a collection of functions that handle common mathematical operations such as square roots, powers, and trigonometric calculations. These functions work with floating-point values (`double` by default).

## **Common Mathematical Functions**

| Function    | Purpose                  | Example            |
| ----------- | ------------------------ | ------------------ |
| `sqrt(x)`   | Square root              | `sqrt(25.0) → 5.0` |
| `pow(x, y)` | Raises *x* to power *y*  | `pow(2, 3) → 8`    |
| `sin(x)`    | Sine of angle (radians)  | `sin(3.14)`        |
| `cos(x)`    | Cosine of angle          | `cos(0)`           |
| `abs(x)`    | Absolute value (integer) | `abs(-4) → 4`      |

> **Note:** `fabs()` is the floating-point version of absolute value.

### **Example: Basic Usage**

```c
#include <stdio.h>
#include <math.h>

int main(void) {
    double x = sqrt(16.0);   // x = 4.0
    double y = pow(2, 3);    // y = 8.0
    double s = sin(3.14159 / 2); // ~1.0

    printf("sqrt(16) = %.1f\n", x);
    printf("2^3 = %.1f\n", y);
    printf("sin(pi/2) = %.2f\n", s);

    return 0;
}
```

---

# **2. Dealing with Time (`time.h`)**

Time handling in C uses a set of related data types and helper functions. At its core is `time_t`, a type representing the number of seconds since the Unix epoch (Jan 1, 1970).

## **Key Time Functions**

| Function      | Purpose                                                   |
| ------------- | --------------------------------------------------------- |
| `time()`      | Returns current time as `time_t`                          |
| `localtime()` | Converts `time_t` to local calendar date/time (struct tm) |
| `ctime()`     | Converts `time_t` to a readable string                    |
| `strftime()`  | Formats time using a custom pattern                       |

### **Example: Getting and Printing Current Time**

```c
#include <stdio.h>
#include <time.h>

int main(void) {
    time_t t;
    time(&t);                     // Fill 't' with current time

    printf("Current time: %s", ctime(&t));  // ctime() already includes a newline

    return 0;
}
```

### **Example: Custom Time Formatting**

```c
#include <stdio.h>
#include <time.h>

int main(void) {
    time_t now = time(NULL);
    struct tm *info = localtime(&now);

    char buffer[64];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", info);

    printf("Formatted time: %s\n", buffer);

    return 0;
}
```

---

# **3. Error Handling (`errno`, `perror()`)**

Errors occur when files fail to open, invalid data is provided, or operations fail. The C library offers tools to help detect and explain problems.

## **The `errno` Variable**

* A global integer set by many library functions when something goes wrong.
* You must `#include <errno.h>` to use it.

## **The `perror()` Function**

* Displays a custom message followed by a description of the last error based on `errno`.

### **Example: Reporting File I/O Errors**

```c
#include <stdio.h>
#include <errno.h>

int main(void) {
    FILE *fp = fopen("missing.txt", "r");

    if (!fp) {
        perror("Error opening file");  // Uses errno internally
        return 1;
    }

    fclose(fp);
    return 0;
}
```

If the file doesn't exist, output looks like:

```
Error opening file: No such file or directory
```

---

# **4. Searching and Sorting (`qsort()`, `bsearch()`)**

C provides fast, generic search/sort routines in `<stdlib.h>`. They operate on *void pointers*, enabling them to sort any data type as long as you supply the comparison logic.

---

## **Sorting with `qsort()`**

`qsort()` needs:

1. Pointer to the array
2. Number of elements
3. Size of each element
4. Comparison function

### **Comparison Function Format**

```c
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
```

### **Example: Sorting Integers**

```c
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int arr[] = {5, 2, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compare);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
```

---

## **Binary Searching with `bsearch()`**

`bsearch()` uses the same comparison function as `qsort()`, but the array must already be sorted.

### **Example: Searching in a Sorted Array**

```c
int key = 9;
int *found = bsearch(&key, arr, n, sizeof(int), compare);

if (found)
    printf("Found %d\n", *found);
else
    printf("Not found\n");
```

---

# **5. Practice Exercise: Type & Run 6**

Below is a sample program that combines today’s topics.

* Calculates a power using `pow()`
* Gets current time
* Sorts an integer array using `qsort()`

---

## **Program: Math + Time + Sorting**

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Comparison function for qsort()
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    // --- Math ---
    double result = pow(3, 4);          // 3^4 = 81
    printf("3^4 = %.0f\n", result);

    // --- Time ---
    time_t now = time(NULL);
    printf("Current time: %s", ctime(&now));  // Includes newline

    // --- Sorting ---
    int nums[] = {4, 1, 9, 3, 7};
    int count = sizeof(nums) / sizeof(nums[0]);

    qsort(nums, count, sizeof(int), compare);

    printf("Sorted numbers: ");
    for (int i = 0; i < count; i++)
        printf("%d ", nums[i]);
    printf("\n");

    return 0;
}
```

### **Possible Output**

```
3^4 = 81
Current time: Tue Nov 25 15:21:08 2025
Sorted numbers: 1 3 4 7 9
```

---

## **ASCII Diagram: Flow of the Program**

```
+------------------+
| Start Program    |
+---------+--------+
          |
          v
+------------------+
| Compute pow()    |
+---------+--------+
          |
          v
+------------------+
| Get time()       |
| Convert via ctime|
+---------+--------+
          |
          v
+------------------+
| qsort() array    |
+---------+--------+
          |
          v
+------------------+
| Print results    |
+---------+--------+
          |
          v
+------------------+
| End Program      |
+------------------+
```

---

# **Summary of Key Points**

* The C library contains powerful modules for mathematics, handling time, managing errors, and performing generic algorithms like sorting and searching.
* `<math.h>` offers useful numeric tools such as `sqrt()`, `pow()`, and trigonometric functions.
* `<time.h>` lets you capture the current moment, convert it to readable forms, and format it.
* `<errno.h>` and `perror()` simplify error reporting in file and system operations.
* `<stdlib.h>` provides `qsort()` and `bsearch()`—flexible, fast utilities that work with any data type through comparison callbacks.
* Mastering these functions helps you avoid reinventing the wheel and write efficient, expressive C programs.


