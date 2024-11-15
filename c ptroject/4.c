#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct WordFreq {
    char word[50];
    int frequency;
};

// Function to compare two WordFreq structs for sorting
int compare(const void *a, const void *b) {
    return ((struct WordFreq*)b)->frequency - ((struct WordFreq*)a)->frequency;
}

int main() {
    char text[1000];
    
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    char *token = strtok(text, " \n");
    struct WordFreq wordFreqList[100];  // Assuming a maximum of 100 words
    int wordCount = 0;

    while (token != NULL) {
        int i;
        for (i = 0; i < wordCount; ++i) {
            if (strcmp(wordFreqList[i].word, token) == 0) {
                // Increment the frequency if the word is already in the list
                wordFreqList[i].frequency++;
                break;
            }
        }

        if (i == wordCount) {
            strcpy(wordFreqList[wordCount].word, token);
            wordFreqList[wordCount].frequency = 1;
            wordCount++;
        }

        token = strtok(NULL, " \n");
    }

    qsort(wordFreqList, wordCount, sizeof(struct WordFreq), compare);

    printf("\nWord Frequency Count (Descending Order):\n");
    for (int i = 0; i < wordCount; ++i) {
        printf("%s: %d\n", wordFreqList[i].word, wordFreqList[i].frequency);
    }

    return 0;
}
