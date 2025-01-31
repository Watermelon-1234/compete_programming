// lexicographic first dfs. transform to rooted tree
#include <bits/stdc++.h>
using namespace std;
#define N 50010
vector<int> adj[N]; // neighbor
vector<int> child[N];
vector<int> tour;
// rooting tree at from v, parent=p
void root(int p, int v) {
    // except for parent, all neighbors are children
    for (int u: adj[v]) {
        if (u!=p) {
            child[v].push_back(u);
            root(v,u);
        }
    }
}
void tsp(int v) {
    tour.push_back(v);
    for (int ch: child[v]) { // for each branch
        tsp(ch);
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
        total+=w;
    }
    root(-1,0);
    for (int i=0; i<n; i++) // sort children
        sort(child[i].begin(), child[i].end());
    tsp(0);
    assert(tour.size()==2*n-1);
    printf("%d\n",total*2);
    printf("%d",tour[0]);
    for (int i=1;i<tour.size();i++)
        printf(" %d",tour[i]);
    printf("\n");
    return 0;
}
