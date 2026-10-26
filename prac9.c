/*
    Data Structures Practical 9
    Aim: Develop a program to implement and demonstrate
         DFS and BFS graph traversal techniques.
*/

#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

/* Depth First Search */
void DFS(int vertex)
{
    int i;

    printf("%d ", vertex);
    visited[vertex] = 1;

    for(i = 0; i < n; i++)
    {
        if(graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

/* Breadth First Search */
void BFS(int start)
{
    int queue[MAX];
    int visited[MAX] = {0};

    int front = 0;
    int rear = 0;

    int vertex, i;

    queue[rear] = start;
    rear++;

    visited[start] = 1;

    while(front < rear)
    {
        vertex = queue[front];
        front++;

        printf("%d ", vertex);

        for(i = 0; i < n; i++)
        {
            if(graph[vertex][i] == 1 && visited[i] == 0)
            {
                queue[rear] = i;
                rear++;

                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j;
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    /* Initialize visited array for DFS */
    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("\nDFS Traversal: ");
    DFS(start);

    printf("\nBFS Traversal: ");
    BFS(start);

    return 0;
}