#include <stdio.h>
int visited[10], q[10];
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
int n = 8, front = 0, rear = -1;
void bfs(int v)
{

    int i;
    for (i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
        {
            q[++rear] = i;
            visited[i] = 1;
            printf("%d", i);
        }
    }
    if (front <= rear)
    {
        bfs(q[front++]);
    }
}

int main()
{
    int v,i;
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("enter vertex to start");
    scanf("%d", &v);
    visited[i] = 1;
    printf("%d", v);
    bfs(v);
}