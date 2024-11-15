#include <stdio.h>
#include <string.h>

// Function to find the length of LCS
int lcs(char* X, char* Y, int m, int n) {
    int L[m+1][n+1];

    // Build the LCS table in bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i-1] == Y[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
            } else {
                L[i][j] = (L[i-1][j] > L[i][j-1]) ? L[i-1][j] : L[i][j-1];
            }
        }
    }

    return L[m][n];
}

// Main function
int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    
    int m = strlen(X);
    int n = strlen(Y);
    
    printf("Length of LCS is %d\n", lcs(X, Y, m, n));
    
    return 0;
}
