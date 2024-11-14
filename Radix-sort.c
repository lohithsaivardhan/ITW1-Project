#include <stdio.h>
#include <stdlib.h>

// Function to get the maximum number in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Counting sort function to sort the elements based on the current digit
void countingSort(int arr[], int n, int exp) {
    int output[n];  // Output array to store sorted values
    int count[10] = {0};  // Count array for digits (0 to 9)

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] to be the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] contains sorted numbers
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Main function to perform radix sort
void radixSort(int arr[], int n) {
    // Get the maximum element to know the number of digits
    int max = getMax(arr, n);

    // Do counting sort for every digit. Note that the exp (exponent) is 10^i
    // where i is the current digit we are sorting by
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    // Perform Radix Sort
    radixSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
