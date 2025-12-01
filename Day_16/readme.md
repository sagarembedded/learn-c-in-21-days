Below is a **fully original**, detailed explanation of **Day 16: Using Disk Files** modeled after the *structure* typically used in *Sams Teach Yourself C in 21 Days*, but **without copying any copyrighted wording**.

---

# **Day 16: Using Disk Files**

Working with files lets your C programs store information permanently, long after the program stops running. In this lesson, you’ll learn how C represents files, how to open and close them, and how to read and write data in both text and binary formats.

---

# **1. Streams and Disk Files**

## **What Is a Stream?**

A *stream* is an abstraction that represents a flow of data. Instead of your program dealing directly with the hardware (keyboard, disk, printer), C creates a uniform interface—streams—so you use the same functions for many kinds of input and output.

Examples of streams:

* Keyboard input stream
* Console output stream
* Disk file streams

## **Files as Streams**

When you open a file in C, you don’t manipulate it directly; you access it through a stream. C uses the `FILE` structure—defined in `<stdio.h>`—to keep track of file state such as:

* Current position in the file
* Whether the file is open for reading or writing
* Buffering status

## **Standard File Pointers**

C automatically provides three basic streams:

| Stream   | Description                          |
| -------- | ------------------------------------ |
| `stdin`  | Standard input (keyboard by default) |
| `stdout` | Standard output (screen by default)  |
| `stderr` | Error output (screen by default)     |

You can create additional file pointers for disk files:

```c
FILE *fp;    // pointer to a file stream structure
```

---

# **2. Types of Disk Files**

## **Sequential vs Random Access**

### **Sequential Access**

Data is processed from beginning to end, in order.

```
[Record1] → [Record2] → [Record3] → ...
           ^ current position moves forward
```

Ideal for:

* Logs
* Simple text files
* Files processed once per run

### **Random Access**

The program jumps to any part of the file using file-position functions.

```
|---A---|---B---|---C---|---D---|
                 ^
              jump here directly
```

Used for:

* Databases
* Indexed records
* Binary structured data

## **Text vs Binary Files**

### **Text Files**

* Data stored as readable characters.
* Formatting conversions occur automatically (newline translation, number parsing).

Example:

```
42
hello
```

### **Binary Files**

* Data written exactly as stored in memory (byte-for-byte).
* Efficient for large data sets or non-textual information (images, structs).

---

# **3. Using Filenames**

You pass a filename to `fopen()` as a string.

### **Relative Path**

```c
fopen("data/output.txt", "w");
```

(Starts from the program’s current working directory.)

### **Absolute Path**

```c
fopen("/home/user/project/log.txt", "a");
fopen("C:\\Users\\Me\\Desktop\\notes.txt", "r");
```

---

# **4. Opening a File**

### **Basic Example**

```c
FILE *fp = fopen("example.txt", "r"); // open for reading
if (fp == NULL) {
    printf("Error opening file\n");
}
```

### **File Modes**

| Mode    | Meaning                           |
| ------- | --------------------------------- |
| `"r"`   | Read text; file must exist        |
| `"w"`   | Write text; creates or overwrites |
| `"a"`   | Append text; creates if not exist |
| `"rb"`  | Read binary                       |
| `"wb"`  | Write binary                      |
| `"ab"`  | Append binary                     |
| `"r+"`  | Read/write text                   |
| `"rb+"` | Read/write binary                 |

---

# **5. Writing and Reading File Data**

## **Formatted Text I/O**

### **Writing Using `fprintf()`**

```c
FILE *fp = fopen("scores.txt", "w");
if (!fp) return 1;

fprintf(fp, "Name: %s\n", "Alex");
fprintf(fp, "Score: %d\n", 92);

fclose(fp);
```

### **Reading Using `fscanf()`**

```c
FILE *fp = fopen("scores.txt", "r");
char name[50];
int score;

fscanf(fp, "Name: %s", name);
fscanf(fp, "Score: %d", &score);

fclose(fp);
```

---

## **Binary File I/O**

### **Writing Using `fwrite()`**

```c
FILE *fp = fopen("nums.bin", "wb");
int data[3] = {10, 20, 30};

fwrite(data, sizeof(int), 3, fp);   // write 3 ints
fclose(fp);
```

### **Reading Using `fread()`**

```c
FILE *fp = fopen("nums.bin", "rb");
int buffer[3];

fread(buffer, sizeof(int), 3, fp);  // read 3 ints
fclose(fp);
```

Inline comment explanation:

* `sizeof(int)` tells C how big each element is.
* The third argument specifies how many elements to transfer.

---

# **6. File Buffering: Closing & Flushing**

## **Buffering**

Most file operations don’t write directly to disk—they write to a *buffer*.
The system occasionally flushes the buffer to the disk for efficiency.

## **`fclose()`**

* Flushes the buffer
* Releases system resources
* Ensures data is fully written

## **`fflush()`**

Forces a flush *without closing*:

```c
fflush(fp); // ensure data is written immediately
```

Useful in logging applications.

---

# **7. Sequential vs Random File Access**

## **Sequential Access Flow**

```
[Start] → (read next) → (read next) → (read next)
```

## **Random Access Tools**

### **`fseek()`**

Moves the file pointer.

```c
fseek(fp, 0, SEEK_SET);    // beginning
fseek(fp, 10, SEEK_CUR);   // current + 10 bytes
fseek(fp, -5, SEEK_END);   // end - 5 bytes
```

### **`ftell()`**

Reports the byte offset:

```c
long pos = ftell(fp);
```

### **`rewind()`**

Returns to start (shortcut for `fseek(fp, 0, SEEK_SET)`):

```c
rewind(fp);
```

## **ASCII Diagram of Pointer Movement**

```
File: | A | B | C | D | E | F |
        ^ start

fseek(fp, 3, SEEK_CUR);

File: | A | B | C | D | E | F |
                      ^ now here
```

---

# **8. Detecting End of File**

`feof()` allows you to check whether you have reached the end:

```c
while (!feof(fp)) {
    fgets(buffer, sizeof(buffer), fp);
    printf("%s", buffer);
}
```

(Be careful: `feof()` only becomes true *after* a read attempt fails.)

---

# **9. File Management Functions**

| Function                      | Purpose                           |
| ----------------------------- | --------------------------------- |
| `remove("file.txt")`          | Deletes a file                    |
| `rename("old.txt","new.txt")` | Changes a filename                |
| `tmpfile()`                   | Creates an unnamed temporary file |

Example:

```c
rename("draft.txt", "final.txt");
remove("olddata.bin");
```

---

# **10. Using Temporary Files**

`tmpfile()` creates a temporary file that automatically disappears when closed.

```c
FILE *fp = tmpfile();
if (!fp) return 1;

fprintf(fp, "Temporary data\n");
rewind(fp);
```

Use this for:

* Intermediate calculations
* Scratch storage during processing

---

# **11. Practice Exercise: Type & Run 5**

Below is a small program that writes data to a file, then reads it back.

### **Program**

```c
#include <stdio.h>

int main(void) {
    FILE *fp;

    // --- Write phase ---
    fp = fopen("practice.txt", "w");
    if (!fp) {
        printf("Unable to open file for writing.\n");
        return 1;
    }

    // Write some lines
    fprintf(fp, "Line 1: Hello!\n");
    fprintf(fp, "Line 2: This is a test.\n");
    fprintf(fp, "Line 3: C file I/O is useful.\n");

    fclose(fp); // flush data to disk

    // --- Read phase ---
    fp = fopen("practice.txt", "r");
    if (!fp) {
        printf("Unable to reopen file for reading.\n");
        return 1;
    }

    char buffer[100];

    printf("Contents of file:\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer); // print each line as read
    }

    fclose(fp);

    return 0;
}
```

### **Expected Output**

```
Contents of file:
Line 1: Hello!
Line 2: This is a test.
Line 3: C file I/O is useful.
```

### **ASCII Diagram of the Flow**

```
 Program
    |
    v
+-----------+
| Write to  |
| practice.txt
+-----------+
    |
    v
Disk File (saved)
    |
    v
+-----------+
| Read from |
| practice.txt
+-----------+
    |
    v
Console Output
```

---

# **Summary of Key Points**

* C treats files as **streams**, allowing a uniform way to do I/O.
* Use `FILE *` pointers and `fopen()` to open files in various modes.
* **Text files** store readable characters; **binary files** store raw bytes.
* `fprintf()`/`fscanf()` handle formatted text; `fwrite()`/`fread()` work with binary data.
* Always use `fclose()` (and `fflush()` when needed) to ensure data reaches the disk.
* Sequential access reads data in order; random access allows jumping around using `fseek()` and `ftell()`.
* `feof()` helps detect when you’ve reached the end of a file.
* C includes helper functions such as `remove()`, `rename()`, and `tmpfile()` for file management.
* Understanding file I/O unlocks persistent storage and more complex program capabilities.

---


