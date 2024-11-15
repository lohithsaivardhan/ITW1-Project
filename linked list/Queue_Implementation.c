#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure for a queue
typedef struct Queue {
    Node* front; // pointer to the front node
    Node* rear; // pointer to the rear node
} Queue;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to initialize an empty queue
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// Function to enqueue an element
void enqueue(Queue* q, int data) {
    Node* newNode = newNode(data);
    if (q->rear == NULL) {
        // queue is empty, set both front and rear
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue an element
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1; // or some error value
    }
    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL; // queue is now empty
    }
    free(temp);
    return data;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Function to display the queue
void displayQueue(Queue* q) {
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 14);
    enqueue(&q, 22);
    enqueue(&q, 6);

    printf("Queue: ");
    displayQueue(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Queue: ");
    displayQueue(&q);

    return 0;
}
