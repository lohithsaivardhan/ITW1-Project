#include <stdio.h>

#define MAX 5

// Structure to represent a circular queue
struct CircularQueue {
    int arr[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
void initQueue(struct CircularQueue* q) {
    q->front = q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct CircularQueue* q) {
    return (q->front == 0 && q->rear == MAX - 1) || (q->front == q->rear + 1);
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* q) {
    return q->front == -1;
}

// Function to enqueue (insert) an element
void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to dequeue (remove) an element
int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

// Function to display the queue
void displayQueue(struct CircularQueue* q) {
   
