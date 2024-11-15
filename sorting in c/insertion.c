#include <stdio.h>

void insertionSort(int array[], int n) {
    int i, element, j;

    for (i = 1; i < n; i++) {
        element = array[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are greater than key by one position */
        while (j >= 0 && array[j] > element) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = element;
    }
}

int main() {
    int data[] = {9, 5, 1, 4, 3};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    insertionSort(data, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
