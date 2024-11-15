#include <stdio.h>
#include <ctype.h>

// Function to count the number of words in a string
int countWords(char str[]) {
    int count = 0;
    int i = 0;
    
    // Loop through the string
    while (str[i] != '\0') {
        // Skip any spaces or non-alphanumeric characters
        while (str[i] != '\0' && isspace(str[i])) {
            i++;
        }

        // If we encounter a non-space character, it's the start of a word
        if (str[i] != '\0') {
            count++;  // Increment word count
            // Skip the rest of the characters of the word
            while (str[i] != '\0' && !isspace(str[i])) {
                i++;
            }
        }
    }
    
    return count;
}

int main() {
    char str[100];

    // Prompt user for input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  // Read the entire line of input, including spaces

    // Call the function to count the number of words
    int wordCount = countWords(str);

    // Output the number of words
    printf("Number of words: %d\n", wordCount);

    return 0;
}
