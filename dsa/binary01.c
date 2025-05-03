#include <stdio.h>

void swap(int a[], int x, int y) {
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

void sort(int a[], int n) {
    int start = 0, end = n - 1;
    int count = 0;
    while (start <= end) {
        if (a[start] == 0) {
            start++;
        }
        else if (a[end] == 1) {
            end--;
        } 
        else {
            swap(a, start, end);
            count++;
            start++;
            end--;
        }
    }
    printf("Total swaps: %d\n", count);
}

int main() {
    int a[] = {0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}