#include <stdio.h>

// Function to print the array
void printarray(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
}

// Function to perform Selection Sort
void selectionsort(int a[], int n){
    printf("Running selection sort...\n");

    int indexofmin, temp;

    // Loop for each position in the array (except the last one)
    for (int i = 0; i < n - 1; i++)
    {
        indexofmin = i;  // Assume the current position has the minimum value

        // Find the actual minimum element in the unsorted part
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[indexofmin])  // If a smaller element is found
            {
                indexofmin = j;  // Update indexofmin
            }
        }

        // Swap the found minimum element with the current element at index i
        temp = a[i];
        a[i] = a[indexofmin];
        a[indexofmin] = temp;

        // Now, element at position i is in its correct sorted place
    }
}

// Main function
int main()
{
    int a[] = {3, 5, 2, 13, 2};  // Sample array
    int n = 5;                   // Size of the array

    printarray(a, n);            // Print original array
    selectionsort(a, n);         // Sort the array
    printarray(a, n);            // Print sorted array

    return 0;
}
