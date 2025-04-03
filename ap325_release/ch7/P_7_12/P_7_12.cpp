// Prim algorithm O(mlogn) using PQ
#include<bits/stdc++.h>
using namespace std;
#define N 10010
#define oo 1000000001

vector<pair<int,int> > adj[N]; //Adjacency list
int d[N], parent[N];
bool done[N]={false};

int main() {
    int n, m;
    // input data
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;i++) {
        int u,v,t;
        scanf("%d%d%d", &u, &v, &t);
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }
    // initial
    int source=0;
    for (int i=0;i<n;i++) d[i]=oo;
    for (int i=0;i<n;i++) parent[i]=-1;
    priority_queue<pair<int,int>> PQ; // (-d[], vertex)
    PQ.push({d[source]=0,source});
    while (!PQ.empty()) { // converge one vertex each iteration
        auto p=PQ.top(); // find min d[] of not-done vertex
        PQ.pop();
        int v=p.second;
        if (done[v]) continue; // already done, discard
        done[v] = true;
        // update neighbor
        for (auto e: adj[v]) {
            int u=e.first, w=e.second;
            //if (done[u]) continue; // not necessary
            if (w < d[u]) { // shorter via v
                d[u] = w;
                parent[u] = v;
                PQ.push({-d[u], u}); // push a better d[] of u
            }
        }
    }
    int cost=0, cnt=0;
    for (int i=0; i<n; i++) {
        if (d[i]<oo) {
            cost+=d[i];
        } else cnt++;
    }
    if (cnt) printf("-1\n");
    else printf("%d\n", cost);
    return 0;
}

