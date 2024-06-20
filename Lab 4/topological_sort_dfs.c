#include <stdio.h>

int s[100];         
int res[100];
int m=0;            

void dfs(int u, int n, int a[n][n]);
void dfs_tp(int n, int a[n][n]);

void dfs_tp(int n, int a[n][n]){
   
    for(int i=0;i<n;i++)
        s[i]=0;
   
    for(int u=0; u<n; u++){
        if(s[u]==0)
            dfs(u,n,a);
    }
}

void dfs(int u, int n, int a[n][n]){
   
    s[u]=1;    
    res[m]=u;
    m++;
   
    for(int v=0; v<n; v++){
        if(a[u][v]==1 && s[v]==0)
            dfs(v,n,a);
    }
}

int main()
{
    int i,n;
    n=6;

    int a[6][6] = {
       
        {0, 0, 0, 0, 0, 0},  // Node 0
        {0, 0, 0, 1, 0, 0},  // Node 1
        {0, 0, 0, 1, 0, 0},  // Node 2
        {0, 0, 0, 0, 0, 0},  // Node 3
        {1, 1, 0, 0, 0, 0},  // Node 4
        {1, 0, 1, 0, 0, 0}   // Node 5
   
    };

   
    dfs_tp(n,a);
   
    printf("DFS Traversal order:\n");
    for(int i=n-1;i>0;i--)
    printf("%d\t",res[i]);

    return 0;
}
