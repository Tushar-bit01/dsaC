#include <stdio.h>

// Function to print the elements of the array
void printarray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d\t", a[i]); // Print each element followed by a tab
    }
    printf("\n"); // Move to the next line after printing all elements
}

// Function to perform insertion sort on the array
void insertionsort(int a[], int n) {
    int key, j;

    // Loop for passes - starts from second element because first is already sorted
    for (int i = 1; i <= n - 1; i++) {
        key = a[i];      // Current element to be inserted in the sorted part
        j = i - 1;        // Index of last element in the sorted part

        // Move elements of a[0..i-1], that are greater than key, one position ahead
        while(j >= 0 && a[j] > key) {
            a[j + 1] = a[j]; // Shift element to the right
            j--;             // Move backward
        }
        a[j + 1] = key; // Insert key at its correct position
    }
}

int main() {
    int a[] = {12, 54, 65, 7, 23, 9}; // Array to be sorted
    int n = 6; // Number of elements in the array

    printarray(a, n);        // Print original array
    insertionsort(a, n);     // Call insertion sort function
    printarray(a, n);        // Print sorted array

    return 0;
}
