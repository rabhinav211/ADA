#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100
#define INF 9999

typedef struct Edge {
    int src, dest, weight;
} Edge;

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*) a;
    Edge* edgeB = (Edge*) b;
    return edgeA->weight > edgeB->weight;
}

void KruskalMST(int graph[MAX][MAX], int numVertices) {
    int E = 0;
    Edge edges[MAX * MAX];
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            if (graph[i][j] != 0 && graph[i][j] != INF) {
                edges[E].src = i;
                edges[E].dest = j;
                edges[E].weight = graph[i][j];
                E++;
            }
        }
    }

    qsort(edges, E, sizeof(edges[0]), compareEdges);

    int parent[numVertices];
    int rank[numVertices];
    for (int v = 0; v < numVertices; v++) {
        parent[v] = v;
        rank[v] = 0;
    }

    Edge result[numVertices];
    int e = 0, i = 0;

    while (e < numVertices - 1 && i < E) {
        Edge next_edge = edges[i++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(parent, rank, x, y);
        }
    }

    printf("Edges in the MST:\n");
    for (i = 0; i < e; i++)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
}

int minDistance(int dist[], bool sptSet[], int numVertices) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < numVertices; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[], int numVertices) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < numVertices; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[MAX][MAX], int src, int numVertices) {
    int dist[numVertices];
    bool sptSet[numVertices];

    for (int i = 0; i < numVertices; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = minDistance(dist, sptSet, numVertices);
        sptSet[u] = true;

        for (int v = 0; v < numVertices; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, numVertices);
}

int main() {
    int numVertices = 5;
    int graph[MAX][MAX] = {
        {0, 2, INF, 6, INF},
        {2, 0, 3, 8, 5},
        {INF, 3, 0, INF, 7},
        {6, 8, INF, 0, 9},
        {INF, 5, 7, 9, 0}
    };

    printf("Kruskal's MST:\n");
    KruskalMST(graph, numVertices);

    printf("\nDijkstra's Shortest Paths from vertex 0:\n");
    dijkstra(graph, 0, numVertices);

    return 0;
}
