Below is an **originally written, detailed tutorial** based on the *concepts* from **Day 14** of *Sams Teach Yourself C in 21 Days, 6th Edition*.
No text is copied; everything is explained freshly in my own words.

---

# **Day 14 — Working with the Screen, Printer, and Keyboard**

Input and output (I/O) in C revolves around the idea of **streams**—abstract channels that allow your program to communicate with the outside world. Today’s lesson explains how streams work, how you interact with the keyboard and screen, and how you redirect these streams to files. You’ll also practice using standard I/O functions like `fprintf()`, `fscanf()`, `fgets()`, and more.

---

# **1. Streams in C**

### **What Is a Stream?**

A **stream** is a logical connection between your program and a data source or destination.
It behaves like a sequence of bytes flowing in one direction:

```
Program  <---- Input Stream ----  Source (Keyboard / File)
Program  ---- Output Stream --->  Destination (Screen / File / Printer)
```

C treats all I/O—whether file access, keyboard input, or screen output—in a uniform way because everything is done through streams.

---

### **The Three Standard Streams**

C automatically opens three streams for every program:

| Stream Name | Direction | Typical Device | Purpose                            |
| ----------- | --------- | -------------- | ---------------------------------- |
| `stdin`     | Input     | Keyboard       | Reading user input                 |
| `stdout`    | Output    | Screen         | Normal program output              |
| `stderr`    | Output    | Screen         | Error messages; usually unbuffered |

Example:

```c
fprintf(stdout, "Hello screen!\n");   // Same as printf()
fprintf(stderr, "Error: Something went wrong!\n");
```

---

### **Using Streams for Reading/Writing**

You can pass these standard streams to any function expecting a `FILE*`.

```c
int value;
fscanf(stdin, "%d", &value);   // reads from keyboard
fprintf(stdout, "You entered: %d\n", value);  // prints to screen
```

---

# **2. Using C’s Stream Functions**

C provides many functions for stream-based input/output.

### **Formatted I/O: `fprintf()` and `fscanf()`**

```c
fprintf(stdout, "Name: %s  Age: %d\n", name, age);
fscanf(stdin, "%d", &number);
```

These behave like `printf()` and `scanf()` but let you specify the destination or source stream.

---

### **String I/O: `fputs()` and `fgets()`**

```c
fputs("Enter text: ", stdout);       // writes a string (no formatting)
fgets(buf, 80, stdin);               // reads a line safely
```

`fgets()` is safer than `gets()` because it limits the number of characters read.

---

### **Other Helpful Stream Functions**

| Function   | Purpose                                          |
| ---------- | ------------------------------------------------ |
| `fputc()`  | Writes a single character                        |
| `fgetc()`  | Reads a single character                         |
| `fflush()` | Forces buffered output to be written immediately |
| `feof()`   | Tests whether end-of-file has been reached       |

---

# **3. Accepting Keyboard Input**

### **Using `scanf()`**

`scanf()` reads formatted input from `stdin`:

```c
int age;
scanf("%d", &age);
```

**Limitations:**

* Stops reading at whitespace
* Can overflow buffers if used to read strings without width limits
* Error checking is vital

---

### **Using `getchar()`**

Reads **one character at a time**:

```c
int ch;
ch = getchar();   // waits for a single character
```

---

### **Using `gets()` (deprecated) and safer alternatives**

`gets()` is unsafe and removed from modern C standards.

Use **`fgets()`** instead:

```c
char name[30];
fgets(name, sizeof(name), stdin);   // reads up to 29 characters + '\0'
```

---

### **Keyboard Input Example**

```c
#include <stdio.h>

int main(void) {
    char buffer[40];

    printf("Enter a line of text: ");
    fgets(buffer, sizeof(buffer), stdin);   // safe input

    printf("You typed: %s", buffer);
    return 0;
}
```

---

# **4. Controlling Screen Output**

### **Formatting with Escape Sequences**

| Sequence | Meaning                     |
| -------- | --------------------------- |
| `\n`     | Newline (move to next line) |
| `\t`     | Horizontal tab              |
| `\\`     | Backslash                   |
| `\"`     | Double quote                |
| `\r`     | Carriage return             |
| `\a`     | Beep (if supported)         |

Example:

```c
printf("Column1\tColumn2\n");
```

---

### **Optional: Clearing Screen (Platform-Dependent)**

On Windows:

```c
system("cls");
```

On Linux / macOS:

```c
system("clear");
```

Not portable—avoid in production code.

---

# **5. Redirecting Input and Output**

Shell operators can redirect a program’s streams.

### **Redirect Output (`stdout`)**

```
program > output.txt
```

### **Redirect Input (`stdin`)**

```
program < input.txt
```

### **Redirect Error Output (`stderr`)**

```
program 2> error.log
```

### **Combined Example**

Suppose your program contains:

```c
fprintf(stdout, "Normal output\n");
fprintf(stderr, "Error output\n");
```

Running it like this:

```
./a.out > out.txt 2> err.txt
```

Results in two separate files:

* `out.txt` contains “Normal output”
* `err.txt` contains “Error output”

---

# **6. Using `fprintf()`**

`fprintf()` sends formatted output to any stream, including files.

```c
#include <stdio.h>

int main(void) {
    FILE *fp = fopen("output.txt", "w");
    if (!fp) {
        perror("File open failed");
        return 1;
    }

    fprintf(fp, "Hello %s\n", "World");
    fclose(fp);
    return 0;
}
```

Important points:

* Always check `fopen()` for success.
* Always close files with `fclose()`.

---

# **7. Practice Exercise**

### **Goal**

Write a program that:

1. Reads input from the keyboard
2. Displays it on the screen
3. Writes the same text to a file using `fprintf()`
4. Properly opens and closes the output file

---

### **ASCII Flow Diagram**

```
   Keyboard
       |
       v
   +---------+     Screen (stdout)
   | Program |-------------------->
   |         |
   |         |-----> File (output.txt)
   +---------+
```

---

### **Example Program**

```c
#include <stdio.h>

int main(void) {
    char line[100];

    // Prompt user
    printf("Type a sentence: ");
    fgets(line, sizeof(line), stdin);   // read from keyboard

    // Write to screen
    printf("You entered: %s", line);

    // Write to file
    FILE *fp = fopen("output.txt", "w");
    if (!fp) {
        perror("Unable to open file");
        return 1;
    }

    fprintf(fp, "User typed: %s", line);  // write with fprintf()
    fclose(fp);

    printf("The text was also saved to output.txt\n");
    return 0;
}
```

### **Expected Output (screen)**

```
Type a sentence: Hello world!
You entered: Hello world!
The text was also saved to output.txt
```

---

# **Summary of Key Points**

* A **stream** is a generalized channel used by C for all input/output.
* C provides three built-in streams: `stdin`, `stdout`, and `stderr`.
* Functions like `fprintf()`, `fscanf()`, `fgets()`, and `fputs()` work on both files and console streams.
* Prefer `fgets()` over `gets()` for safe keyboard input.
* Escape sequences let you format output cleanly.
* The shell can redirect streams using `>`, `<`, and `2>`.
* `fprintf()` is the most flexible way to send formatted text to files or alternative streams.

Understanding streams is a foundation for mastering file handling, console I/O, and user interaction in C programs.

---
