
#include<stdio.h>
int n = 8;
int adj[8][8] = {
    0, 1, 1, 1, 0, 0, 0, 0,
    1, 0, 0, 0, 1, 1, 0, 0,
    1, 0, 0, 0, 0, 0, 1, 0,
    1, 0, 0, 0, 0, 0, 0, 1,
    0, 1, 0, 0, 0, 0, 0, 1,
    0, 1, 0, 0, 0, 0, 0, 1,
    0, 0, 1, 0, 0, 0, 0, 1,
    0, 0, 0, 1, 1, 1, 1, 0
    
};
int visited[8];

void dfs(int v) {
    int i;
    for(int i=0; i<n; i++) {
        if(adj[v][i] == 1 && visited[i] == 0) {
            printf("%d\t", i);
            visited[i] = 1;
            dfs(i);
        }
    }
}

int main() {
    int i, j, v;
    for(i=0; i<n; i++) {
        visited[i] = 0;
    }

    printf("Enter first vertex: ");
    scanf("%d", &v);

    printf("%d \t",v);
    visited[v] = 1;
    dfs(v);
    return 0;
}