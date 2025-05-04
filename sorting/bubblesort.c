#include <stdio.h>

// Function to print the array elements
void printarray(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%d\t", a[i]);  // Print each element with a tab space
    }
    printf("\n");  // New line after printing all elements
}

// Function to perform Bubble Sort
void bubblesort(int a[], int n){
    int temp;

    // Outer loop runs n-1 times for passes
    for(int i = 0; i < n - 1; i++){  // Total passes = n-1

        // Inner loop for comparing adjacent elements
        for(int j = 0; j < n - 1 - i; j++){  // Reduce comparisons each pass

            // If current element is greater than next, swap them
            if(a[j] > a[j + 1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        // After each pass, the largest element moves to the end
    }
}

// Main function
int main()
{
    int a[] = {12, 54, 65, 7, 23, 9};  // Unsorted array
    int n = 6;                         // Number of elements

    printarray(a, n);      // Print array before sorting
    bubblesort(a, n);      // Sort the array using bubble sort
    printarray(a, n);      // Print array after sorting

    return 0;
}
