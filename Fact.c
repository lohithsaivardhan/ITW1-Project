#include <stdio.h>

// Function to calculate the factorial of a number
long long factorial(int n) {
    long long fact = 1;  // Initialize result to 1
    for (int i = 1; i <= n; i++) {
        fact *= i;  // Multiply fact by each number from 1 to n
    }
    return fact;
}

int main() {
    int num;

    // Ask the user for input
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check if the number is negative
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        // Call the factorial function and display the result
        printf("Factorial of %d is %lld\n", num, factorial(num));
    }

    return 0;
}
