#include <stdio.h>

int main() {
    int n;

    // Prompt the user for input
    printf("Enter the number of rows for the inverted pyramid: ");
    scanf("%d", &n);

    // Print the inverted pyramid of stars
    for (int i = n; i >= 1; i--) {
        // Print spaces for alignment
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Print stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }

        // Move to the next line after each row
        printf("\n");
    }

    return 0;
}
