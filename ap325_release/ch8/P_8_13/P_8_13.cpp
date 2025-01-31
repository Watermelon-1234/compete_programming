// P-8-13 min domination set of a tree
// top-down DP d1(r): min cost with root,
// d01(r): min cost without root but root is dominated
// d00(r): min cost without root and root is not necessarily dominated
// d1(r)=w(r)+sum(min(d00(v),d1(v)): all child v of r), d00<=d01
// d00(r)=sum(min(d1(v),d01(v)))
// d01(r)=sum(min(d1(v),d01(v)))+ max(0,min(d1[v}-d01(v))), not all d01
#include <bits/stdc++.h>
using namespace std;

#define N 100020
#define oo 1000000000
vector<int> adj[N];
int w[N], d1[N], d01[N], d00[N];
// set min domination set of subtree(r) with parent p
void dfs(int r, int p) {
    d1[r] = w[r], d01[r]=oo, d00[r]=0;
    for (int v: adj[r]) {
        if (v==p) continue;
        dfs(v,r);
        d1[r] += min(d00[v], d1[v]);
        d00[r] += min(d1[v], d01[v]);
        d01[r] = min(d01[r], d1[v]-d01[v]);
    }
    d01[r] = d00[r] + max(0, d01[r]);
    return;
}

int main() {
    int i, n;
	scanf("%d",&n);
    for (i=1; i<=n; i++) scanf("%d",&w[i]);
	for (i=1; i<n; i++) {
        int u,v;
        if (scanf("%d%d",&u, &v)!=2)
            fprintf(stderr,"input error\n");
        adj[u].push_back(v);
        adj[v].push_back(u);
	}
    // parent of root(1) is set to 0(dummy);
    dfs(1,0);
	printf("%d\n", min(d1[1], d01[1]));
    return 0;
}
