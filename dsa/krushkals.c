#include <stdio.h>

#define MAX 100


int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union_set(int u, int v) {
    int a = find(u);
    int b = find(v);
    parent[a] = b;
}

int main() {
    int n = 5; // Number of vertices
    int edgeCount = 7;
    int edges[7][3] = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    // Sort edges by weight (Bubble Sort)
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                int temp0 = edges[j][0], temp1 = edges[j][1], temp2 = edges[j][2];
                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][0] = temp0;
                edges[j + 1][1] = temp1;
                edges[j + 1][2] = temp2;
            }
        }
    }

    // Initialize parent array
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int totalCost = 0, count = 0;
    printf("Edges in MST:\n");

    for (int i = 0; i < edgeCount && count < n - 1; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        if (find(u) != find(v)) {
            union_set(u, v);
            totalCost += wt;
            count++;
            printf("%d - %d (Weight: %d)\n", u, v, wt);
        }
    }

    printf("Total Minimum Cost: %d\n", totalCost);
    return 0;
}
