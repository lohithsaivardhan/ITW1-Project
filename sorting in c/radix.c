#include <stdio.h>
#include <stdlib.h>

#define RADIX 10
#define WIDTH 3

void countSort(int* arr, int n, int exp) {
    int output[n];
    int count[RADIX], i;

    for (i = 0; i < RADIX; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        count[(arr[i]/exp)%RADIX]++;

    for (i = 1; i < RADIX; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i]/exp)%RADIX] - 1] = arr[i];
        count[(arr[i]/exp)%RADIX]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int* arr, int n) {
    int m = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > m)
            m = arr[i];

    for (int exp = 1; m/exp > 0; exp *= RADIX)
        countSort(arr, n, exp);
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);

    radixsort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
