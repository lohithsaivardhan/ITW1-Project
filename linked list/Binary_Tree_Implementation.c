#include <stdio.h>
#include <stdlib.h>

// Structure for defining a Node in a Binary Tree
typedef struct Node {
    int data; // Data stored in the node
    struct Node* left; // Pointer to the left child node
    struct Node* right; // Pointer to the right child node
} Node;

// Function to create a new node in the Binary Tree
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the Binary Tree
void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = newNode(data);
    } else {
        Node* current = *root;
        while (1) {
            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = newNode(data);
                    break;
                }
                current = current->left;
            } else {
                if (current->right == NULL) {
                    current->right = newNode(data);
                    break;
                }
                current = current->right;
            }
        }
    }
}

// Function to perform in-order traversal of the Binary Tree
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;

    // Insert nodes into the Binary Tree
    insert(&root, 40);
    insert(&root, 20);
    insert(&root, 50);
    insert(&root, 10);
    insert(&root, 30);

    // Perform in-order traversal
    printf("Traversal of a binary tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
