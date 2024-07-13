#include <stdio.h>
#define v 100
int top = -1;

void indegree(int a_matrix[v][v], int n, int in[v])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a_matrix[i][j])
            {
                in[j]++;
            }
        }
    }
}

void toposort(int a_matrix[v][v], int n)
{
    int in[v] = {0};
    int topo[v];
    int k = 0;
    int s[v] = {0};
    
    indegree(a_matrix, n, in);
    
    for (int i = 0; i < n; i++)
    {
        if (in[i] == 0)
        {
            top++;
            s[top] = i;
        }
    }
    
    while (top != -1)
    {
        int vertex = s[top];
        top--;
        topo[k++] = vertex;
        
        for (int i = 0; i < n; i++)
        {
            if (a_matrix[vertex][i])
            {
                in[i]--;
                if (in[i] == 0)
                {
                    top++;
                    s[top] = i;
                }
            }
        }
    }
    
    if (k != n)
    {
        printf("cycle exists");
    }
    else
    {
        printf("the topological sort: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", topo[i] + 1);
        }
    }
}

int main()
{
    int a_matrix[v][v] = {
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };
    int n = 6; 

    toposort(a_matrix, n);
    return 0;
}
