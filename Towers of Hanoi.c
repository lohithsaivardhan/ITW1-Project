#include <stdio.h>

// Function to move disks from source to destination
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    
    // Input number of disks
    printf("Enter number of disks: ");
    scanf("%d", &n);
    
    // Solve the Towers of Hanoi puzzle
    towerOfHanoi(n, 'A', 'B', 'C');
    
    return 0;
}
