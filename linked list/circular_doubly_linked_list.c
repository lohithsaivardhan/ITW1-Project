#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        // If the list is empty, set the new node as both the first and last node
        newNode->prev = newNode;
        newNode->next = newNode;
        *head = newNode;
    } else {
        // Insert the new node before the current first node
        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = NULL;
        *head = newNode;
    }
}

// Function to insert a new node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        // If the list is empty, set the new node as both the first and last node
        newNode->prev = newNode;
        newNode->next = newNode;
        *head = newNode;
    } else {
        // Find the last node in the list
        Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        // Insert the new node after the last node
        newNode->prev = current;
        newNode->next = *head;
        current->next = newNode;
        (*head)->prev = newNode;
    }
}

// Function to remove a node from the list
void removeNode(Node** head, int data) {
    Node* current = *head;
    while (current != NULL) {
        if (current->data == data) {
            // Remove the node
            if (current->prev == current) {
                // If the node is the only one in the list, set head to NULL
                *head = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

// Function to print the list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
        if (current == head) {
            break; // We've reached the beginning of the list again
        }
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert some nodes
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 30);

    // Print the list
    printList(head);

    // Remove a node
    removeNode(&head, 20);

    // Print the list again
    printList(head);

    return 0;
}
