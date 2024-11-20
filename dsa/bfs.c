#include <stdio.h>
int visited[10], q[10];
int adjacency_matrix[8][8] = {
    0, 1, 1, 1, 0, 0, 0, 0,
    1, 0, 0, 0, 1, 1, 0, 0,
    1, 0, 0, 0, 0, 0, 1, 0,
    1, 0, 0, 0, 0, 0, 0, 1,
    0, 1, 0, 0, 0, 0, 0, 1,
    0, 1, 0, 0, 0, 0, 0, 1,
    0, 0, 1, 0, 0, 0, 0, 1,
    0, 0, 0, 1, 1, 1, 1, 0
    
};
int num_of_vertices=8, front = 0, rear = -1;

void bfs(int vertex) {
    int i;
    for (i = 0; i < num_of_vertices; i++) {
        if (adjacency_matrix[vertex][i] == 1 && visited[i] == 0) {
            q[++rear] = i;
            visited[i] = 1;
            printf("%d ", i);
        }
    }
    if (front <= rear) {
        bfs(q[front++]);
    }
}

int main() {
    int i, j, vertex;

    for(i = 0; i < num_of_vertices; i++) {
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &vertex);
    visited[vertex] = 1;

    printf("BFS:\n");
    printf("%d ", vertex);
    bfs(vertex);
    return 0;
}