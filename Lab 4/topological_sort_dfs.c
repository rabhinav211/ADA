#include <stdio.h>
#include <stdlib.h>

#define v 6

int stack[v];
int top = -1;

void push(int vertex) {
    stack[++top] = vertex;
}

int pop() {
    return stack[top--];
}

void dfs(int vertex, int visited[v], int adj[v][v]) {
    visited[vertex] = 1;
    for (int i = 0; i < v; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i, visited, adj);
        }
    }
    push(vertex);
}

void toposort(int adj[v][v]) {
    int visited[v] = {0};

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj);
        }
    }

    printf("Topological sort: ");
    while (top != -1) {
        printf("%d ", pop() + 1); // Adding 1 to match the expected output format
    }
    printf("\n");
}

int main() {
    int a_matrix[v][v] = {
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    toposort(a_matrix);
    return 0;
}
