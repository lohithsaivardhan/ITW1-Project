#include <stdio.h>

int main() {
    int m, n, p, q;
    
    // Input dimensions for first matrix
    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d %d", &m, &n);
    
    // Input dimensions for second matrix
    printf("Enter the number of rows and columns of matrix 2: ");
    scanf("%d %d", &p, &q);
    
    // If the matrices are not compatible for multiplication
    if (n != p) {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    // Declare the matrices
    int A[m][n], B[p][q], result[m][q];
    
    // Input elements for matrix A
    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input elements for matrix B
    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    // Initialize result matrix to 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            result[i][j] = 0;
        }
    }

    // Matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print the result matrix
    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
