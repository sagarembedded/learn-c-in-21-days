Below is an **original**, fully rewritten tutorial on **Day 8: Using Numeric Arrays**, inspired by the structure of *Sams Teach Yourself C in 21 Days, 6th Ed.* but **not copying** any text from the book.

---

# **Day 8: Using Numeric Arrays**

Numeric arrays are a fundamental tool in C programming. They let you manage groups of related values in an organized and efficient way. Today’s lesson introduces what arrays are, how to declare and use them, and how to process them with loops.

---

# **1. What Is an Array?**

An **array** in C is a block of consecutive memory locations that all hold values of the **same data type**. Each value in the array is called an **element**, and each element can be accessed by its **index**.

Arrays are helpful when you need to work with many values—such as temperature readings, grades, or measurements—without creating dozens of separate variables.

### **Why arrays are useful**

* They keep data organized in a structured format.
* They make loops and repetitive tasks simple.
* They help reduce errors and make code shorter and cleaner.

### **ASCII Memory Diagram**

Below is a visual representation of an array of five integers:

```
numbers[5]

Index:      0      1      2      3      4
           +------+------+------+------+------+
Memory:    |  12  |  15  |  18  |  21  |  24  |
           +------+------+------+------+------+
```

Each box is one array element, stored right next to the others in memory.

---

# **2. Naming and Declaring Arrays**

### **Rules for naming arrays**

Array names follow the same rules as other identifiers:

* Must start with a letter or underscore.
* Can contain letters, digits, and underscores.
* Case sensitive (`prices` ≠ `Prices`).
* Cannot use C keywords (`int`, `for`, etc.).

### **Declaring Arrays**

You specify:

1. The **data type**
2. The **array name**
3. The **number of elements**

Example declarations:

```c
int numbers[5];                   // Declaration without initialization

float prices[3] = {1.5, 2.0, 3.5}; // Declaration with initialization
```

### **Understanding Array Size and Indexing**

* The value inside the brackets (`[5]`, `[3]`) is the **array size**, i.e., how many elements it holds.
* Array indexing starts at **0**, so an array of 5 elements has valid indices:
  `0, 1, 2, 3, 4`.

### **Array Declaration Summary**

| Declaration Example                       | Type   | Size | Initialized?              |
| ----------------------------------------- | ------ | ---- | ------------------------- |
| `int a[10];`                              | int    | 10   | No                        |
| `float prices[3] = {1.5, 2.0, 3.5};`      | float  | 3    | Yes (full initialization) |
| `double vals[4] = {2.0, 4.0};`            | double | 4    | Partial (others = 0)      |
| `char digits[5] = {'1','2','3','4','5'};` | char   | 5    | Yes                       |

---

# **3. Accessing and Using Array Elements**

### **Assigning Values**

You access an element using its index:

```c
numbers[0] = 10;   // First element
numbers[1] = 20;   // Second element
```

### **Using Loops with Arrays**

Loops make array processing easy:

```c
for(int i = 0; i < 5; i++) {
    numbers[i] = i * 2;       // Assign a computed value
    printf("%d ", numbers[i]); // Print each element
}
```

This loop:

* Runs from `i = 0` to `i = 4`
* Fills the array with even numbers
* Prints: `0 2 4 6 8`

### **Stay Within Bounds**

Accessing an index outside the array (e.g., `numbers[5]` in a 5-element array) is dangerous:

* It may overwrite unrelated memory.
* It often leads to unpredictable behavior or crashes.

Always ensure your loop conditions stay within the array’s size.

---

# **4. Practice Exercise**

Write a program that:

1. Declares an integer array of 5 elements.
2. Fills it with values from user-defined logic.
3. Computes the sum and average of the elements.
4. Displays the results.

### **Sample Program**

```c
#include <stdio.h>

int main(void) {
    int values[5];      // Array declaration
    int sum = 0;
    
    // Assign values to the array
    for (int i = 0; i < 5; i++) {
        values[i] = (i + 1) * 10;  // e.g., 10, 20, 30, 40, 50
        sum += values[i];          // Accumulate sum
    }

    // Display elements
    printf("Array elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", values[i]);  // Print each element
    }

    // Calculate and show average
    float average = sum / 5.0;
    printf("\nSum = %d\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}
```

### **Expected Output**

```
Array elements: 10 20 30 40 50 
Sum = 150
Average = 30.00
```

### **ASCII Diagram: Traversal Illustration**

```
values array:

Index:      0     1     2     3     4
           +-----+-----+-----+-----+-----+
           | 10  | 20  | 30  | 40  | 50  |
           +-----+-----+-----+-----+-----+
             ^     ^     ^     ^     ^
             |     |     |     |     |
             Loop visits elements in order (i = 0 → 4)
```

---

# **Summary of Key Points**

* An array groups many values of the **same type** into a single structure.
* Array names follow standard identifier rules.
* Arrays use **zero-based indexing**.
* Use loops to fill, process, and display array elements.
* Accessing out-of-range elements leads to undefined behavior.
* Arrays are the foundation of more advanced data structures in C.

If you'd like, I can also generate:

* A quiz based on today’s material
* Additional exercises
* Visualizations of multi-dimensional arrays

Just let me know!
