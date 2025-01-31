//ch7  demo adjacency list
#include <bits/stdc++.h>
using namespace std;
#define N 20
int main() {
    vector<int> adj[N]; // nbr[i]: neighbors of vertex i
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++) {
        int from, to;
        scanf("%d%d", &from, &to);
        adj[from].push_back(to);
    }
    printf("adjacency list:\n");
    for (int i=0;i<n;i++) {
        printf("%d: ",i);
        for (int v: adj[i])
            printf("%d ",v);
        printf("\n");
    }
    printf("deg = ");
    for (int i=0;i<n;i++)
        printf("%d ", (int)adj[i].size());
    printf("\n");
    return 0;
}
