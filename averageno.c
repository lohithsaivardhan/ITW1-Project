#include <stdio.h>

int main() {
    int n;
    double sum = 0.0, number;

    // Prompt user for how many numbers they want to average
    printf("Enter the number of values: ");
    scanf("%d", &n);

    // Check if the user entered a valid number of values
    if (n <= 0) {
        printf("Please enter a positive integer for the number of values.\n");
        return 1;  // Exit the program with an error code
    }

    // Get the numbers from the user and calculate the sum
    for (int i = 1; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%lf", &number);
        sum += number;
    }

    // Calculate the average
    double average = sum / n;

    // Output the average
    printf("The average is: %.2lf\n", average);

    return 0;
}
