#include <stdio.h>

int main() {
    int num1, num2, gcd, lcm, temp1, temp2;
    
    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    // Store the numbers in temporary variables
    temp1 = num1;
    temp2 = num2;
    
    // Calculate GCD using Euclidean algorithm
    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    gcd = num1;
    
    // Calculate LCM
    lcm
