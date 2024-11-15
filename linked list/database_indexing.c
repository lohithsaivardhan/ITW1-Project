#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int key;
    void* data;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(int key, void* data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the linked list
void insertNode(Node** head, int key, void* data) {
    Node* newNode = createNode(key, data);
    if (*head == NULL || (*head)->key > key) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next && current->next->key < key) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to search for a key in the linked list
void* searchNode(Node* head, int key) {
    Node* current = head;
    while (current) {
        if (current->key == key) {
            return current->data;
        }
        current = current->next;
    }
    return NULL; // key not found
}

int main() {
    // Create an empty linked list
    Node* head = NULL;

    // Insert some sample data into the index
    insertNode(&head, 1, "Record 1");
    insertNode(&head, 2, "Record 2");
    insertNode(&head, 3, "Record 3");

    // Search for a key
    void* result = searchNode(head, 2);
    if (result) {
        printf("Found record: %s\n", (char*)result);
    } else {
        printf("Key not found\n");
    }

    return 0;
}
