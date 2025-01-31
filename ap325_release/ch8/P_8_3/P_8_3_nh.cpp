// P-8-3 tree median, O(nh) method
#include <bits/stdc++.h>
using namespace std;
#define N 100010
vector<pair<int,int>> adj[N]; // (neighbor, length) of i
int parent[N], d[N]={0};
// compute distance
void dfs(int v, int p) {
    for (auto e: adj[v]) {
        if (e.first != p) {
            d[e.first] = d[v] + e.second;
            dfs(e.first, v);
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i=1;i<n;i++) {
        int w;
        scanf("%d%d", &parent[i], &w);
        adj[i].push_back({parent[i],w});
        adj[parent[i]].push_back({i,w});
    }
    parent[0]=-1; // root has no parent
    int num[N]={0}; // number of node in the subtree
    for (int i=0; i<n; i++) { // for each vertex
        int v=i;
        while (v>=0) { // add itself to all its ancestors
            num[v]++;
            v=parent[v];
        }
    }
    // find median
    bool flag[N]={false}; // if having a child >=n/2;
    for (int i=1; i<n; i++)
        if (num[i]>=(n+1)/2) flag[parent[i]]=true;
    int median=0;
    for ( ; median<n; median++) {
        if (num[median]>=(n+1)/2 && !flag[median])
            break;
    }
    // compute d[v] the distance from median to v
    long long int total=0;
    dfs(median, -1);
    for (int i=0;i<n;i++)
        total += d[i];
    printf("%d\n%lld\n", median, total);
    return 0;
}
