#include <stdio.h>
#include <stdbool.h>

#define N 8  // You can change this value for a different board size

// Function to print the chessboard
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Check if a queen can be placed on board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check this column on upper side
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve N-Queens problem
bool solveNQueens(int board[N][N], int row) {
    // If all queens are placed, return true
    if (row >= N) {
        return true;
    }

    // Consider this row and try all columns
    for (int col = 0; col < N; col++) {
        // Check if placing queen at board[row][col] is safe
        if (isSafe(board, row, col)) {
            // Place queen
            board[row][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueens(board, row + 1)) {
                return true;
            }

            // If placing queen doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    // If the queen cannot be placed in any column, return false
    return false;
}

// Main function
int main() {
    int board[N][N] = {0};

    if (solveNQueens(board, 0)) {
        printSolution(board);
    } else {
        printf("Solution does not exist.\n");
    }

    return 0;
}
