#include <stdio.h>
#include <stdlib.h>

// Node structure for Fibonacci Heap
typedef struct Node {
    int key;
    struct Node* child;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
    int degree;
    int marked;
} Node;

// Fibonacci Heap structure
typedef struct Heap {
    Node* min;
    int count;
    Node** trees;
} Heap;

// Initialize a new Fibonacci Heap
Heap* fibonacci_heap_init() {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->min = NULL;
    h->count = 0;
    h->trees = (Node**)malloc(sizeof(Node*) * 128); // initial capacity
    return h;
}

// Insert a new node into the Fibonacci Heap
void fibonacci_heap_insert(Heap* h, int key) {
    Node* x = (Node*)malloc(sizeof(Node));
    x->key = key;
    x->child = NULL;
    x->parent = NULL;
    x->left = x;
    x->right = x;
    x->degree = 0;
    x->marked = 0;

    if (h->min == NULL) {
        h->min = x;
    } else {
        // Find the correct position for x in the circular doubly linked list
        Node* y = h->min;
        while (y->right != h->min && y->key <= key) {
            y = y->right;
        }
        x->left = y;
        x->right = y->right;
        y->right = x;
        if (x->right == h->min) {
            h->min = x;
        }
    }

    h->count++;
}

// Consolidate trees with the same degree
void fibonacci_heap_consolidate(Heap* h) {
    int max_degree = 0;
    for (int i = 0; i <= h->count; i++) {
        if (h->trees[i] != NULL) {
            max_degree = i;
        }
    }

    for (int i = 0; i <= max_degree; i++) {
        h->trees[i] = NULL;
    }

    Node* x;
    for (x = h->min; x != h->min; x = x->right) {
        int degree = x->degree;
        while (h->trees[degree] != NULL) {
            Node* y = h->trees[degree];
            h->trees[degree] = NULL;
            if (x->key > y->key) {
                Node* temp = x;
                x = y;
                y = temp;
            }
            x->right = y->right;
            y->right = x;
            x->left = y;
            y->left = x;
            degree++;
        }
        h->trees[degree] = x;
    }

    h->min = NULL;
    for (int i = 0; i <= max_degree; i++) {
        if (h->trees[i] != NULL) {
            if (h->min == NULL || h->trees[i]->key < h->min->key) {
                h->min = h->trees[i];
            }
        }
    }
}

// Extract the minimum node from the Fibonacci Heap
int fibonacci_heap_extract_min(Heap* h) {
    if (h->min == NULL) {
        return -1; // heap is empty
    }

    int min_key = h->min->key;
    Node* x = h->min;

    if (x->child != NULL) {
        // Cut all children of x and make them roots
        Node* child = x->child;
        x->child = NULL;
        while (child != NULL) {
            Node* next = child->right;
            child->right = x->right;
            x->right = child;
            child = next;
        }
    }

    // Consolidate trees
    fibonacci_heap_consolidate(h);

    // Update min pointer
    if (h->min == NULL) {
        h->min = NULL;
    } else {
        h->min = h->min->right;
    }

    h->count--;
    free(x);
    return min_key;
}

int main() {
    Heap* h = fibonacci_heap_init();

    fibonacci_heap_insert(h, 3);
    fibonacci_heap_insert(h, 7);
    fibonacci_heap_insert(h, 2);
    fibonacci_heap_insert(h, 11);

    printf("Minimum key: %d\n", fibonacci_heap_extract_min(h)); // prints 2

    return 0;
}
