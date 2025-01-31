//ch7  demo adjacency matrix
#include <bits/stdc++.h>
using namespace std;
#define N 20
int main() {
    int adj[N][N]={0};
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++) {
        int from, to;
        scanf("%d%d", &from, &to);
        adj[from][to]=1;
    }
    printf("adjacency matrix:\n");
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++)
            printf("%d ",adj[i][j]);
        printf("\n");
    }
    printf("deg = ");
    int deg[N]={0};
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++)
            deg[i] += adj[i][j];
        printf("%d ", deg[i]);
    }
    printf("\n");
    return 0;
}
