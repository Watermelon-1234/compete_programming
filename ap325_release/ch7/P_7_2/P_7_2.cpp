// P-7-2, max weight component, adjacency list
#include <bits/stdc++.h>
using namespace std;
#define N 50100
int n, m, s;
vector<int> adj[N];
int w[N]; // weight of vertices
bool visit[N] = {false};

// return the total weight can be reached from s
int dfs(int s) {
    int weight=w[s];
    visit[s]=true;
    for (int u: adj[s]) {
        if (!visit[u])
            weight += dfs(u); // total weight
    }
    return weight;
}

int main() {
    scanf("%d%d", &n, &m);
    int total=0;
    for (int i=0;i<n;i++) {
        scanf("%d", &w[i]);
        total += w[i];
    }
    for (int i=0; i<m; i++) { // each edge
        int u,v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v); // v is a neighbor of u
        adj[v].push_back(u); // u also a neighbor of v
    }
    int maxw=0; // max total weight
    for (int v=0; v<n; v++) {
        // search the weight of component of v
        if (!visit[v])
            maxw=max(maxw,dfs(v));
    }
    printf("%d\n", maxw);
    // for checking
    fprintf(stderr, "ans=%d, total=%d\n",maxw, total);
    return 0;
}
