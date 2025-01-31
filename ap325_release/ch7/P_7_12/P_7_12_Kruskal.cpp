// Kruskal algorithm O(mlogn)
#include<bits/stdc++.h>
using namespace std;
#define N 10010
#define oo 1000000001
struct EDGE {
    int u,v,w;
};
bool cmp(EDGE &p, EDGE &q) {
    return p.w < q.w;
}
int p[N]; // parent
int rfind(int v) {
    if (p[v]<0) return v;
    return p[v]=rfind(p[v]);
}
// union two set, return true if really merge
bool joint(int u, int v) {
    int r1=rfind(u), r2=rfind(v);
    if (r1==r2) return false;
    if (p[r1]<p[r2]) {
        p[r1] += p[r2];
        p[r2] = r1;
    } else {
        p[r2] += p[r1];
        p[r1] = r2;
    }
    return true;
}

int main() {
    int n, m;
    // input data
    scanf("%d%d", &n, &m);
    vector<EDGE> edge;
    for(int i=0;i<m;i++) {
        int u,v,t;
        scanf("%d%d%d", &u, &v, &t);
        edge.push_back({u,v,t});
    }
    // initial
    for (int i=0;i<n;i++) p[i]=-1; // each vertex a set
    sort(edge.begin(), edge.end(), cmp); // sort by weight
    int cost=0, n_edge=0;
    for (EDGE e: edge) {
        if (joint(e.u, e.v)) { // insert an edge
            cost += e.w;
            n_edge++;
        }
    }
    if (n_edge < n-1) printf("-1\n");
    else printf("%d\n", cost);
    return 0;
}

