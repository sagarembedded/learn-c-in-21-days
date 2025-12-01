Below is a *fully original*, **non-copyrighted**, tutor-style explanation of
**Day 17: Manipulating Strings** inspired by the structure of *Sams Teach Yourself C in 21 Days (6th Ed.)*, but written entirely in new wording.

---

# **Day 17 — Manipulating Strings in C**

Strings in C are simply **arrays of characters** that terminate with a **null character (`'\0'`)**. The standard library (`<string.h>` and `<ctype.h>`) provides many tools that make handling text easier and safer. Today you’ll learn how to measure, copy, join, compare, search, and convert strings, as well as use character-classification functions.

---

# **1. Determining String Length**

### `strlen()`

The function:

```c
size_t strlen(const char *s);
```

returns the number of characters *before* the terminating null byte.

### Example

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char msg[] = "Hello!";
    size_t len = strlen(msg);      // strlen counts: H e l l o ! = 6 characters

    printf("Length = %zu\n", len); // prints: Length = 6
    return 0;
}
```

**Important:**
`strlen()` scans the entire string until it finds `'\0'`, so it must only be used with properly terminated strings.

---

# **2. Copying Strings**

## `strcpy()` — full copy

```c
char *strcpy(char *dest, const char *src);
```

Copies all characters from `src` (including the final `'\0'`) to `dest`.

### Example

```c
char dst[20];
char src[] = "Sample";

strcpy(dst, src);   // OK because dst has enough space
```

## `strncpy()` — bounded copy

```c
char *strncpy(char *dest, const char *src, size_t n);
```

Copies **at most** `n` characters.
If `src` is shorter than `n`, extra bytes are padded with `'\0'`.
If `src` is longer, **no null terminator is added automatically**.

### Example with safety

```c
char dst[6];
char src[] = "Sample";

// Copy only 5 characters and THEN manually add '\0'
strncpy(dst, src, 5);
dst[5] = '\0';     // Essential if src >= 5
```

### **Buffer Safety Rule**

Always make sure your destination array is large enough.
If the buffer is too small, you risk **buffer overflow**, which leads to crashes or security problems.

---

# **3. Concatenating Strings**

## `strcat()` — append entire string

```c
char *strcat(char *dest, const char *src);
```

Appends `src` to the end of `dest`.

## `strncat()` — append limited characters

```c
char *strncat(char *dest, const char *src, size_t n);
```

### Example

```c
char text[20] = "Hello";
char addon[] = " World";

strcat(text, addon);  // Result: "Hello World"
```

### Important:

* There **must** be enough space for both strings plus the `'\0'`.
* Both functions automatically place a `'\0'` at the end.

---

# **4. Comparing Strings**

## `strcmp()`

```c
int strcmp(const char *s1, const char *s2);
```

## `strncmp()`

```c
int strncmp(const char *s1, const char *s2, size_t n);
```

### Return values

| Return value | Meaning                                      |
| ------------ | -------------------------------------------- |
| `< 0`        | `s1` comes *before* `s2` (lexicographically) |
| `0`          | Strings are identical                        |
| `> 0`        | `s1` comes *after* `s2`                      |

### Example

```c
if (strcmp("apple", "banana") < 0) {
    // true because "apple" < "banana"
}
```

---

# **5. Searching Strings**

## `strchr()` — find first occurrence of a character

```c
char *strchr(const char *s, int c);
```

## `strstr()` — find first occurrence of a substring

```c
char *strstr(const char *haystack, const char *needle);
```

### Examples

```c
char text[] = "C programming";

/* Find character */
char *p = strchr(text, 'p');     // -> points to "programming"

/* Find substring */
char *q = strstr(text, "gram");  // -> points to "gramming"
```

If not found, both return **NULL**.

---

# **6. String Conversions**

## Converting strings to numbers

| Function   | Converts to | Notes                                      |
| ---------- | ----------- | ------------------------------------------ |
| `atoi()`   | `int`       | Simple, no error reporting                 |
| `atof()`   | `double`    | Simple, no error reporting                 |
| `strtol()` | `long`      | **Provides error checking**, handles bases |

### Examples

```c
int a = atoi("42");           // 42
double b = atof("3.14");      // 3.14

char *end;
long c = strtol("101", &end, 10);  // 101 in base 10
```

`strtol()` sets `end` to point at the first invalid character.
Use it when you need safety.

## Converting numbers to strings: `sprintf()`

```c
sprintf(buffer, "%d", 123);   // writes "123" to buffer
```

---

# **7. Miscellaneous String & Character Functions**

These come from `<ctype.h>`.

| Function    | Purpose                           |
| ----------- | --------------------------------- |
| `toupper()` | Convert letter to uppercase       |
| `tolower()` | Convert letter to lowercase       |
| `isdigit()` | Checks if character is a digit    |
| `isalpha()` | Checks if character is alphabetic |

### Example

```c
char c1 = toupper('a');  // 'A'
char c2 = tolower('Q');  // 'q'

isdigit('5');  // true
isalpha('A');  // true
```

---

# **8. Differences Between `atoi()`, `atof()`, `strtol()`**

| Function   | Error Checking | Type Returned | Best Use                      |
| ---------- | -------------- | ------------- | ----------------------------- |
| `atoi()`   | ❌ No           | `int`         | Quick & dirty parsing         |
| `atof()`   | ❌ No           | `double`      | Simple floating-point parsing |
| `strtol()` | ✅ Yes          | `long`        | Robust input handling         |

### Safe `strtol()` example:

```c
char *end;
long value = strtol("456xyz", &end, 10);

if (*end != '\0') {
    printf("Extra characters detected!\n");
}
```

---

# **9. Character Test Functions (`<ctype.h>`)**

Useful for validating input or parsing text.

### Example

```c
if (isdigit('9')) {
    printf("It is a digit.\n");
}

if (isalpha('k')) {
    printf("It is a letter.\n");
}
```

---

# **10. Practice Exercise — Mini String Processor**

### **Goal**

Write a program that:

1. Reads a string.
2. Copies it to another buffer.
3. Appends a suffix.
4. Compares original and modified strings.
5. Searches for a character.

### **Example Program**

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char input[50];
    char copy[50];

    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline if present
    input[strcspn(input, "\n")] = '\0';

    strcpy(copy, input);             // 1. Copy string

    strcat(copy, "_suffix");         // 2. Append suffix

    // 3. Compare original and modified
    if (strcmp(input, copy) == 0) {
        printf("Strings are identical.\n");
    } else {
        printf("Strings differ.\n");
    }

    // 4. Search for character 'a'
    char *pos = strchr(input, 'a');
    if (pos) {
        printf("'a' found at index %ld\n", pos - input);
    } else {
        printf("'a' not found.\n");
    }

    printf("Original: %s\n", input);
    printf("Modified: %s\n", copy);

    return 0;
}
```

### **Sample Output**

```
Enter text: panda
Strings differ.
'a' found at index 1
Original: panda
Modified: panda_suffix
```

---

# **ASCII Memory Diagram**

```
Original string ("panda"):
+---+---+---+---+---+----+
| p | a | n | d | a | \0 |
+---+---+---+---+---+----+

After concatenation ("panda_suffix"):
+---+---+---+---+---+---+---+---+---+---+---+---+----+
| p | a | n | d | a | _ | s | u | f | f | i | x | \0 |
+---+---+---+---+---+---+---+---+---+---+---+---+----+
```

---

# **Summary — Key Points**

* A C string is a character array terminated by `'\0'`.
* `strlen()` counts characters but excludes the terminator.
* Use `strcpy()`/`strncpy()` to copy, and always ensure buffer sizes are large enough.
* Use `strcat()`/`strncat()` to concatenate; always leave room for the null byte.
* `strcmp()` and `strncmp()` compare strings lexicographically.
* `strchr()` and `strstr()` let you locate characters and substrings.
* `atoi()` and `atof()` are simple, but `strtol()` is safer and more flexible.
* `<ctype.h>` provides tools for checking and converting characters.
* Proper string handling prevents bugs and memory errors.

---
