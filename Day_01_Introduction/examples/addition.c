#include <stdio.h>   // Include standard input/output functions

int main() {
    int a, b;                     // Declare two integer variables
    printf("Enter two numbers: "); // Prompt the user for input
    scanf("%d %d", &a, &b);        // Read two integers from user and store in a and b
    printf("Sum = %d\n", a + b);   // Calculate sum and print it
    return 0;                       // Exit program successfully
}
