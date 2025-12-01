Below is a **completely original explanation** of *Day 10: Working with Characters and Strings*, following the structure and topics you requested and inspired by how the book organizes material—without copying any text from the actual book.

---

# **Day 10 — Working with Characters and Strings**

C programs frequently need to handle textual data—letters, digits, words, and full sentences. Today’s lesson explores how the C language represents individual characters using the `char` type and how it builds strings from arrays of characters. You’ll also learn how to input, output, and manipulate this kind of data safely and effectively.

---

# **1. The `char` Data Type**

## **A single character in one byte**

The C language stores an individual character using the **`char`** data type. In most systems, a `char` occupies **1 byte (8 bits)**. This allows it to store values in the range −128 to 127 (signed) or 0 to 255 (unsigned), depending on the compiler.

Although `char` variables hold numeric values internally, we usually work with them using **character literals**:

```c
char letter = 'A';   // single character literal
char digit  = '7';
char symbol = '#';
```

Character literals are always written **between single quotes**.

---

## **ASCII and Character Encoding**

All characters correspond to integer codes defined by a character encoding standard.
The most common is **ASCII**, where:

* `'A'` has the value **65**
* `'a'` has the value **97**
* `'0'` has the value **48**

Because characters are stored as numbers, you can perform comparisons and arithmetic operations on them.

---

# **2. Using Character Variables**

## **Displaying characters**

`printf()` prints a single character using the **`%c`** formatter:

```c
char ch = 'X';
printf("The character is: %c\n", ch);
```

## **Reading a character**

`scanf()` reads a character using `%c`:

```c
char input;
scanf("%c", &input);
```

> **Note:** `%c` reads even whitespace (spaces, tabs, newlines).
> If you want to skip whitespace, use `" %c"` (with a leading space).

---

## **Operations on characters**

Because characters are stored as integers, you can compare or modify them:

```c
char c = 'A';

if (c < 'Z')
    printf("c is before Z alphabetically\n");

char next = c + 1;   // 'B' because ASCII('A') + 1 = ASCII('B')
printf("Next letter: %c\n", next);
```

---

# **3. Using Strings**

## **Strings are arrays of characters**

A **string** in C is simply an array of `char` terminated by the **null character** `'\0'`.
Example:

```c
char name[20] = "Alice";
```

Memory layout:

| Index | 0 | 1 | 2 | 3 | 4 | 5  | … |
| ----- | - | - | - | - | - | -- | - |
| Value | A | l | i | c | e | \0 | … |

Important rules:

* The compiler adds the terminating `'\0'` automatically for string literals.
* A string variable must be large enough for *all characters plus* the null terminator.

## **Characters vs. Strings**

| Type       | Example | Meaning                           |
| ---------- | ------- | --------------------------------- |
| **char**   | `'A'`   | Single character                  |
| **string** | `"A"`   | Array containing `'A'` and `'\0'` |

Even though they look similar, they behave very differently in memory.

---

# **4. Strings and Pointers**

Because strings are arrays, the array name represents the address of the first character. You can manipulate strings using `char *` pointers:

```c
char name[] = "Alice";
char *ptr = name;    // points to first character: 'A'

while (*ptr != '\0') {
    printf("%c", *ptr);   // print character pointer is on
    ptr++;                // move to next character
}
```

This technique is very common in C string-handling functions.

### Pointer-based view of a string

```
name:  A   l   i   c   e  \0
       ^   
       |
      ptr
```

After each `ptr++`, the pointer moves to the next memory cell.

---

# **5. Strings Without Arrays**

String literals appear frequently in programs:

```c
printf("Hello, World!\n");
```

These literals exist in **read-only program memory**, so:

* You **can** reference them with a `char *`.
* You **must not** attempt to modify them.

Example (incorrect):

```c
char *msg = "Hello";
msg[0] = 'J';   // ❌ Undefined behavior — string literal is immutable
```

If you need a modifiable string, copy it into an array:

```c
char msg[] = "Hello";  // stored in writable memory
msg[0] = 'J';          // OK
```

---

# **6. Displaying Strings and Characters**

### **Printing characters**

```c
char ch = 'K';
printf("Letter: %c\n", ch);
```

### **Printing strings**

```c
char word[] = "keyboard";
printf("Word: %s\n", word);
```

### **Formatting examples**

```c
printf("%10s\n", word);   // right-align in 10 spaces
printf("%-10send\n", word); // left-align
```

---

# **7. Reading Strings from the Keyboard**

## **Using `scanf()`**

Basic usage:

```c
char name[20];
scanf("%s", name);    // reads until whitespace
```

Limitation:

* Stops on whitespace → "John Doe" becomes `"John"` only.

You can restrict input length to prevent overflow:

```c
scanf("%19s", name);  // leave room for '\0'
```

---

## **Using `fgets()` — the safer method**

`fgets()` reads an entire line including spaces:

```c
char line[50];
fgets(line, sizeof(line), stdin);   // safe: prevents overflow
```

It stops when:

* The buffer is full,
* A newline is read,
* or EOF occurs.

### Important: `fgets()` retains the newline (`\n`) if there's space.

---

## **`gets()` should not be used**

Older C programs used `gets()`, but it has been removed from the standard because it cannot prevent buffer overflow.

---

# **8. Practice Exercise**

Here’s a small program that:

1. Reads a string from the user,
2. Prints each character individually,
3. Reverses the string and prints it.

---

## **Program: String Traversal and Reversal**

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char text[100];

    printf("Enter a line of text:\n");

    // Use fgets() to safely read a line, including spaces
    fgets(text, sizeof(text), stdin);

    // Remove trailing newline if it exists
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
        len--;   // adjust length
    }

    printf("\nCharacters in the string:\n");

    // Print characters one at a time
    for (size_t i = 0; i < len; i++) {
        printf("text[%zu] = %c\n", i, text[i]);
    }

    // Reverse the string using two pointers
    char *left  = text;
    char *right = text + len - 1;

    while (left < right) {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }

    printf("\nReversed string:\n%s\n", text);

    return 0;
}
```

### **Sample Output**

```
Enter a line of text:
Hello World

Characters in the string:
text[0] = H
text[1] = e
text[2] = l
text[3] = l
text[4] = o
text[5] =  
text[6] = W
text[7] = o
text[8] = r
text[9] = l
text[10] = d

Reversed string:
dlroW olleH
```

---

# **ASCII Memory Diagram Example**

Imagine `char msg[] = "Cat";` stored in memory:

```
Index:      0     1     2     3
Memory:    'C'   'a'   't'   '\0'
Address: 1000  1001  1002  1003
```

Pointer traversal:

```
ptr → 'C'
ptr+1 → 'a'
ptr+2 → 't'
ptr+3 → '\0'
```

---

# **Summary — Key Takeaways**

* **`char` stores a single character**, using 1 byte; internally characters are numeric ASCII codes.
* A **string is a character array** ending with a **null terminator** `'\0'`.
* Characters are printed with `%c`; strings with `%s`.
* Strings can be accessed or modified using either **arrays or pointers**.
* **String literals are not writable**, even though they are of type `char *`.
* Use **`fgets()`** instead of `scanf("%s")` or the unsafe `gets()`.
* Proper handling of input, pointers, and terminators is essential when working with text in C.

If you'd like, I can also create **practice quizzes**, **step-by-step coding challenges**, or **visual diagrams** to reinforce any of these concepts.
