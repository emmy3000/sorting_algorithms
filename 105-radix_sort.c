#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order using the
 * LSD radix sort algorithm
 *
 * @array: pointer to the array to sort
 * @size: size of the array to sort
 */
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to do counting sort of arr[] according to the digit represented by exp
void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to implement Radix sort
void radix_sort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int max = findMax(arr, n);

    // Do counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);

        // Print the array after sorting with each significant digit
        printf("Array after sorting with digit %d: ", exp);
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    radix_sort(arr, n);
    return 0;
}

