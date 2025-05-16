#include <stdio.h>

// Global variables
int n = 5;                      // Number of elements
int targetSum = 10;             // Target sum
int weights[] = {2, 3, 5, 6,4};   // Input weights
int subset[10];                 // Array to store current subset

// Recursive function to find all subsets with the given sum
void sumOfSubsets(int index, int currentSum, int target, int subsetSize) {
    // Base case: if current sum matches target, print the subset
    if (currentSum == target) {
        printf("Subset found: ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;  // Don't stop recursion here to find more subsets
    }

    // Stop recursion if all elements are checked or sum exceeded
    if (index >= n || currentSum > target) {
        return;
    }

    // Include the current weight
    subset[subsetSize] = weights[index];
    sumOfSubsets(index + 1, currentSum + weights[index], target, subsetSize + 1);

    // Exclude the current weight
    sumOfSubsets(index + 1, currentSum, target, subsetSize);
}

int main() {
    printf("Subsets with sum = %d are:\n", targetSum);
    sumOfSubsets(0, 0, targetSum, 0);
    return 0;
}
