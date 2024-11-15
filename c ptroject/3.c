 // Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int main() {
    // Write C code here
    char str[200];
    char word[100];
    printf("Enter string: ");
    gets(str);
    int j = 0; 
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == ' ' || str[i] == ',' || str[i] == ',' && str[i+1] == ' '){
            continue;
        }
        else{
            word[j] = tolower(str[i]);
            j++;
        }
    }
    
    printf("\nWord formed is: \n");
    puts(word);
    int k = strlen(word) - 1; int i = 0;
    while(k>i){
        if(word[i] != word[k]){
            printf("\nFormed word is not palindrome.", word);
            return 0;
        }
        k--;
        i++;
    }
    
    printf("\nFormed word is palindrome.");
}
