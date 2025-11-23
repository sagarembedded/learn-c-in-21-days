#include <stdio.h>          // Include standard input/output functions

int main() {
    const float PI = 3.14159;   // Define a constant for pi
    float radius, area;          // Declare variables for radius and area

    printf("Enter radius of circle: ");  // Prompt user for radius
    scanf("%f", &radius);                // Read radius input

    area = PI * radius * radius;         // Calculate area of circle
    printf("Area of the circle: %.2f\n", area); // Print area rounded to 2 decimals

    return 0;  // Exit program successfully
}
