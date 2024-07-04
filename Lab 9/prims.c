#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 5

int minKey(int n, int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int n, int parent[], int cost[MAX_VERTICES][MAX_VERTICES]) {
    int sum = 0;

    printf("Edges in MST:\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d\n", parent[i], i);
        sum += cost[i][parent[i]];
    }

    printf("Cost of MST is: %d\n", sum);
}


void primMST(int n, int cost[MAX_VERTICES][MAX_VERTICES]) {
    int parent[MAX_VERTICES]; 
    int key[MAX_VERTICES];    
    int mstSet[MAX_VERTICES]; 
    
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;


    for (int count = 0; count < n - 1; count++) {

        int u = minKey(n, key, mstSet);
        mstSet[u] = 1;


        for (int v = 0; v < n; v++) {

            if (cost[u][v] && mstSet[v] == 0 && cost[u][v] < key[v]) {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }

    printMST(n, parent, cost);
}

int main() {
    int n = MAX_VERTICES;
    int cost[MAX_VERTICES][MAX_VERTICES] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    printf("Cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }

    primMST(n, cost);

    return 0;
}
