#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at node i
void maxHeapify(int A[], int n, int i) {
    int largest = i;          // Initialize largest as root
    int l = 2 * i + 1;        // Left child index
    int r = 2 * i + 2;        // Right child index

    // Check if the left child is larger than root
    if (l < n && A[l] > A[largest])
        largest = l;

    // Check if the right child is larger than current largest
    if (r < n && A[r] > A[largest])
        largest = r;

    // If largest is not the root
    if (largest != i) {
        swap(&A[i], &A[largest]); // Swap root with the largest
        maxHeapify(A, n, largest); // Recursively heapify the affected subtree
    }
}

// Function to perform heap sort
void heapSort(int A[], int n) {
// Function to build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(A, n, i);
    }

    // Extract elements from the heap
    for (int i = n - 1; i > 0; i--) {
        swap(&A[0], &A[i]);  // Move the current root to the end
        maxHeapify(A, i, 0); // Heapify the reduced heap
    }
}

// Function to print an array
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Main function to test the heap sort
int main() {
    int A[] = {15, 17, 20, 1, 5, 10, 30};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array:\n");
    printArray(A, n);

    heapSort(A, n);

    printf("Sorted array:\n");
    printArray(A, n);

    return 0;
}
