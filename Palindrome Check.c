#include <stdio.h>
#include <string.h>

int main() {
    char str[100], reversedStr[100];
    
    // Input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character
    str[strcspn(str, "\n")] = '\0';
    
    // Reverse the string
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        reversedStr[i] = str[length - 1 - i];
    }
    reversedStr[length] = '\0';  // Null-terminate the reversed string
    
    // Check if the string is a palindrome
    if (strcmp(str, reversedStr) == 0) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    
    return 0;
}
