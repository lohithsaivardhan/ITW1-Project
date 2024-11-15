#include <stdio.h>
#include <math.h>

int main() {
    int num, temp, remainder, sum = 0, digits = 0;
    
    // Input number
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // Calculate number of digits
    temp = num;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }
    
    // Check if the number is Armstrong
    temp = num;
    while (temp != 0) {
        remainder = temp % 10;
        sum += pow(remainder, digits);
        temp /= 10;
    }
    
    if (sum == num) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }
    
    return 0;
}
