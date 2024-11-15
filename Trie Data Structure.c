#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Trie node structure
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int endOfWord;
};

// Function to create a new Trie node
struct TrieNode* createNode() {
    struct TrieNode* newNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    newNode->endOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to insert a word into the Trie
void insert(struct TrieNode* root, const char* word) {
    struct TrieNode* current = root;
    int index;
    
    for (int i = 0; i < strlen(word); i++) {
        index = word[i] - 'a';
        
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        
        current = current->children[index];
    }
    
    current->endOfWord = 1;
}

// Function to search for a word in the Trie
int search(struct TrieNode* root, const char* word) {
    struct TrieNode* current = root;
    int index;
    
    for (int i = 0; i < strlen(word); i++) {
        index = word[i] - 'a';
        
        if (current->children[index] == NULL) {
            return 0;
        }
        
        current = current->children[index];
    }
    
    return (current != NULL && current->endOfWord);
}

// Main function
int main() {
    struct TrieNode* root = createNode();
    
    insert(root, "hello");
    insert(root, "world");
    
    if (search(root, "hello")) {
        printf("Found 'hello' in Trie.\n");
    } else {
        printf("'hello' not found.\n");
    }

    if (search(root, "world")) {
        printf("Found 'world' in Trie.\n");
    } else {
        printf("'world' not found.\n");
    }
    
    return 0;
}
