#include <stdio.h>
#include <limits.h>

#define N 5

void prims(int graph[N][N]) {
    int visited[N] = {0};
    int edgeCount = 0;
    int totalCost = 0;

    visited[0] = 1;  // Start with node 0

    printf("Edge \tCost\n");

    while (edgeCount < N - 1) {
        int min = INT_MAX;
        int u = -1, v = -1;

        for (int i = 0; i < N; i++) {
            if (visited[i]) {
                for (int j = 0; j < N; j++) {
                    if (!visited[j] && graph[i][j] && graph[i][j] < min) {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("%d - %d\t%d\n", u, v, graph[u][v]);
            visited[v] = 1;
            totalCost += graph[u][v];
            edgeCount++;
        }
    }

    printf("Total cost = %d\n", totalCost);
}

int main() {
    int graph[N][N] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    prims(graph);

    return 0;
}
