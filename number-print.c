#include <stdio.h>

int main() {
    int n;

    // Prompt the user for input
    printf("Enter the number of rows for the pyramid: ");
    scanf("%d", &n);

    // Print the pyramid of numbers
    for (int i = 1; i <= n; i++) {
        // Print spaces to center the numbers
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Print numbers
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("%d", j);
        }

        // Move to the next line after each row
        printf("\n");
    }

    return 0;
}
