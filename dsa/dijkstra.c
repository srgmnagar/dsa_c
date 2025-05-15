#include <stdio.h>
#include <limits.h> // For INT_MAX

#define V 5 // Number of vertices in the graph

// Function to find the vertex with the minimum distance
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];    // dist[i] = shortest distance from src to i
    int visited[V]; // visited[i] = 1 if vertex i is already included

    // Step 1: Initialize distances and visited array
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0; // Distance to source itself is 0

    // Step 2: Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited); 
        visited[u] = 1;

        // Step 3: Update dist[v] for adjacent vertices of u
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Step 4: Print the result
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    // Example graph in the form of an adjacency matrix
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };

    int source = 0;
    dijkstra(graph, source);

    return 0;
}
