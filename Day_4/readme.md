Below is an **original, tutorial-style explanation** of the requested Day 4 material, **not copied from the book**, but organized following the topics and structure typical of that chapter.

---

# **Day 4 — Statements, Expressions, and Operators**

## **1. Statements**

### **What Is a Statement?**

A **statement** in C is a complete instruction telling the compiler to perform some action.
Every statement ends with a **semicolon (`;`)**, except for control statements that use braces `{ }` to group other statements.

### **Types of Statements**

#### **a. Expression Statements**

An expression statement evaluates an expression and optionally stores a result or produces a side effect.

**Examples**

```c
x = 5;      // assignment expression used as a statement
y++;        // increment expression
total = x + y; 
```

#### **b. Function Call Statements**

Calling a function is also a statement when followed by `;`.

```c
printf("Hello!\n");     // function call statement
scanf("%d", &num);      // input function call
```

#### **c. Control Statements**

Control statements change the normal top-to-bottom flow of execution.
These typically use **parentheses** for the condition and **braces `{ }`** for the body.

Examples:

```c
if (x > 0) {            // control statement
    printf("Positive\n");
}

while (n > 0) {         // loop
    n--;
}
```

---

## **2. Understanding Expressions**

### **What Is an Expression?**

An **expression** combines **variables**, **constants**, and **operators** to compute a value.
Expressions appear in assignments, conditions, arithmetic, and function arguments.

### **Examples of Expressions**

#### **Arithmetic Expressions**

```c
a + b
x * 3 - 2
(4 + y) / 2
```

#### **Relational Expressions**

```c
x < 10
a == b
n != 0
```

#### **Logical Expressions**

```c
(x > 0) && (y > 0)
(flag == 1) || (count > 5)
!done
```

#### **Assignment Expressions**

An assignment itself is an expression whose value is the assigned value.

```c
x = 7
z = (y = 4 + 5);        // nested assignment
```

After execution:

* `y` becomes `9`
* `x` becomes `7`
* `z` becomes the value of `y`, which is `9`

### **Readable Expressions**

Although C allows dense, compact expressions, they can reduce readability:

**Avoid**

```c
k = (a = b + c) + (d = e * f) - g++;
```

**Better**

```c
a = b + c;
d = e * f;
k = a + d - g++;
```

---

## **3. Operators**

### **Categories of Operators**

Below are tables summarizing the most common operators.

---

### **Arithmetic Operators**

| Operator | Meaning        | Example  | Result                                         |
| -------- | -------------- | -------- | ---------------------------------------------- |
| `+`      | Addition       | `5 + 3`  | `8`                                            |
| `-`      | Subtraction    | `10 - 4` | `6`                                            |
| `*`      | Multiplication | `2 * 3`  | `6`                                            |
| `/`      | Division       | `7 / 2`  | `3` (integer division), `3.5` (float division) |
| `%`      | Remainder      | `7 % 2`  | `1`                                            |

> **Note:** If both operands are integers, `/` truncates toward zero.

---

### **Assignment Operators**

| Operator | Meaning             | Example  | Equivalent  |
| -------- | ------------------- | -------- | ----------- |
| `=`      | Assign              | `x = 5`  | —           |
| `+=`     | Add and assign      | `x += 3` | `x = x + 3` |
| `-=`     | Subtract and assign | `x -= 2` | `x = x - 2` |
| `*=`     | Multiply and assign | `x *= 4` | `x = x * 4` |
| `/=`     | Divide and assign   | `x /= 2` | `x = x / 2` |
| `%=`     | Modulo and assign   | `x %= 3` | `x = x % 3` |

---

### **Relational Operators**

| Operator | Meaning               | Example  | Result                    |
| -------- | --------------------- | -------- | ------------------------- |
| `==`     | Equal to              | `x == 3` | `1` (true) or `0` (false) |
| `!=`     | Not equal             | `x != 3` | `1` or `0`                |
| `<`      | Less than             | `a < b`  |                           |
| `>`      | Greater than          | `a > b`  |                           |
| `<=`     | Less than or equal    | `x <= y` |                           |
| `>=`     | Greater than or equal | `x >= y` |                           |

---

### **Logical Operators**

| Operator | Meaning     | Example              | Result                    |          |   |          |                            |
| -------- | ----------- | -------------------- | ------------------------- | -------- | - | -------- | -------------------------- |
| `&&`     | Logical AND | `(x > 0) && (y > 0)` | true if **both** are true |          |   |          |                            |
| `        |             | `                    | Logical OR                | `(x > 0) |   | (y > 0)` | true if **either** is true |
| `!`      | Logical NOT | `!flag`              | true if `flag` is false   |          |   |          |                            |

---

## **4. The `if` Statement**

The `if` statement executes code only when a condition evaluates to true.

### **Basic Form**

```c
if (condition) {
    statement;
}
```

### **With else**

```c
if (temperature > 30) {
    printf("Hot\n");
} else {
    printf("Comfortable\n");
}
```

### **Using Operators in Conditions**

```c
if ((age >= 18) && (citizen == 1)) {
    printf("Eligible to vote\n");
}
```

---

## **5. True/False Values in C**

C uses integers to represent truth values:

* **0** → false
* **Any non-zero value** → true

Examples:

```c
if (5) {            // true
    printf("Hello\n");
}

if (0) {            // false
    printf("Won't print\n");
}
```

---

## **6. Operator Precedence**

### **Why Precedence Matters**

Precedence tells C **which operators apply first** when an expression has multiple operators.

Associativity determines whether evaluation occurs **left to right** or **right to left** when operators have the same precedence.

### **Simplified Precedence Table**

| Precedence Level | Operator(s)          | Associativity     |   |               |
| ---------------- | -------------------- | ----------------- | - | ------------- |
| Highest          | `()`, `!`            | Left-to-right     |   |               |
|                  | `*`, `/`, `%`        | Left-to-right     |   |               |
|                  | `+`, `-`             | Left-to-right     |   |               |
|                  | `<`, `<=`, `>`, `>=` | Left-to-right     |   |               |
|                  | `==`, `!=`           | Left-to-right     |   |               |
|                  | `&&`                 | Left-to-right     |   |               |
|                  | `                    |                   | ` | Left-to-right |
| Lowest           | `=`, `+=`, `-=` etc. | **Right-to-left** |   |               |

### **Use Parentheses When in Doubt**

Even though C knows the rules, humans read code better when parentheses clarify intent.

Avoid:

```c
result = a + b * c > d;
```

Better:

```c
result = (a + b * c) > d;
```

---

## **7. Practice Exercise — Type & Run 2**

Here is a program that checks whether a number is **even or odd**.

### **ASCII Flowchart**

```
   +------------------+
   |  Start Program   |
   +--------+---------+
            |
            v
   +------------------+
   | Read number n    |
   +--------+---------+
            |
            v
   +--------------------------+
   | Is n % 2 equal to 0 ?    |
   +--------+-----------------+
        Yes |      | No
            |      |
            v      v
 +------------------+      +------------------+
 | Print "Even"     |      | Print "Odd"      |
 +------------------+      +------------------+
            \        /
             \      /
              v    v
        +----------------+
        | End Program    |
        +----------------+
```

---

### **Example Program**

```c
#include <stdio.h>

int main(void)
{
    int n;                         // variable to store user input

    printf("Enter an integer: ");  // prompt
    scanf("%d", &n);               // read input

    if (n % 2 == 0) {              // use modulo operator to test even/odd
        printf("%d is even.\n", n);
    } else {                       // executes if condition is false
        printf("%d is odd.\n", n);
    }

    return 0;                      // indicate successful program execution
}
```

---

# **Summary of Key Points**

* A **statement** is a complete instruction, normally ending with `;`.
* An **expression** produces a value by combining variables, constants, and operators.
* **Operators** include arithmetic, assignment, relational, and logical types.
* `if` and `if-else` statements control program flow based on expressions.
* In C, **0 is false**, and **any non-zero value is true**.
* Operator **precedence** and **associativity** determine how complex expressions are evaluated—parentheses improve clarity.
* Assignment expressions can be nested, but readability should be prioritized.

If you'd like, I can also generate **Day 4 quizzes**, **extra practice problems**, or **visual memory aids**.
