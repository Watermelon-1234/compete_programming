//ch7  topological sort O(m+n), non-recursive
#include <bits/stdc++.h>
using namespace std;
#define N 20
int main() {
    vector<int> adj[N]; // adjacency list
    int indeg[N]={0};
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++) {
        int from, to;
        scanf("%d%d", &from, &to);
        adj[from].push_back(to);
        indeg[to]++;
    }
    int topo[N], head=0, tail=0; //queue
    // push all indeg==0
    for (int i=0;i<n;i++)
        if (indeg[i]==0)
            topo[tail++]=i; // push
    while (head<tail) { // until queue is empty
        int v=topo[head++]; // pop from queue
        for (int u: adj[v]) {
            if (--indeg[u] ==0)
                topo[tail++] = u;
        }
    }
    // output
    if (tail<n) printf("No a dag\n");
    else {
        for (int i=0;i<n;i++)
            printf("%d ", topo[i]);
        printf("\n");
    }
    return 0;
}
