#include <stdio.h>
#include <string.h>

// Function to reverse the string
void reverseString(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    // Swap characters from both ends until the middle is reached
    while (start < end) {
        // Swap the characters at start and end
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move the indices towards the middle
        start++;
        end--;
    }
}

int main() {
    char str[100];

    // Prompt user to enter a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  // Read a line of input, including spaces

    // Remove the newline character that fgets might leave in the string
    str[strcspn(str, "\n")] = '\0';

    // Reverse the string
    reverseString(str);

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}
