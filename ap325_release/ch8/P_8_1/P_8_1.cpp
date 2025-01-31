// lexicographic first dfs
#include <bits/stdc++.h>
using namespace std;
#define N 50010
vector<int> adj[N]; // neighbor
vector<int> tour;
// dfs from v, parent=p
void dfs(int p, int v) {
    tour.push_back(v);
    for (int u: adj[v]) { // dfs each neighbor
        if (u==p) continue; // except for parent
        dfs(v,u);
        tour.push_back(v);
    }
}
int main() {
    int n, total=0;
    scanf("%d", &n);
    for (int i=0;i<n-1;i++) {
        int u,v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back(v);
        adj[v].push_back(u);
        total += w; // total edge weight
    }
    for (int i=0; i<n; i++)
        sort(adj[i].begin(), adj[i].end());
    dfs(-1,0); // starting at 0, no parent
    assert(tour.size()==2*n-1);
    // output
    printf("%d\n", total*2);
    printf("%d", tour[0]);
    for (int i=1; i<tour.size();i ++)
        printf(" %d", tour[i]);
    printf("\n");
    return 0;
}
