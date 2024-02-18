#include <stdio.h>
#include <stdlib.h>

// Function to get the maximum value in array[]
int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

// Counting sort of array[] according to the digit represented by exp
void counting_sort(int array[], int n, int exp) {
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(array[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    // Copy the output array to array[], so that array[] now contains sorted numbers
    for (i = 0; i < n; i++)
        array[i] = output[i];
}

// The main function to that sorts array[] of size n using Radix Sort
void radix_sort(int array[], int n) {
    // Find the maximum number to know the number of digits
    int max = getMax(array, n);

    // Do counting sort for every digit. Note that instead of passing digit number, exp is passed.
    // exp is 10^i where i is current digit number
    for (int exp = 1; max / exp > 0; exp *= 10)
        counting_sort(array, n, exp);
}

// A utility function to print an array
void print_array(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Driver program to test above functions
int main() {
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original array:\n");
    print_array(array, n);

    radix_sort(array, n);

    printf("Sorted array:\n");
    print_array(array, n);
    return 0;
}
