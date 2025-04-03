//P-7-6 longest and shortest path on dag, recursive DP
// fix bug at 20210708
#include <bits/stdc++.h>
using namespace std;
#define N 10010
#define oo 1000000000
vector<pair<int,int>> pred[N]; // (neighbor, length)
int d[N], p[N]; // min and max distance
// min distance from source
int mind(int t) {
    if (d[t] <= oo) return d[t]; // check memo
    d[t] = oo; // find minimum from each predecessor
    for (auto e: pred[t]) {
        int x=mind(e.first);
        if (x<oo) d[t] = min(d[t], x + e.second);
    }
    return d[t];
}
// max distance from source
int maxd(int t) {
    if (p[t] >= -oo) return p[t];
    p[t] = -oo;
    for (auto e: pred[t]) {
        int x=maxd(e.first);
        if (x>-oo) p[t] = max(p[t], x + e.second);
    }
    return p[t];
}

int main() {
    int n, m, source, goal;
    scanf("%d%d", &n, &m);
    scanf("%d%d", &source, &goal);
    // read predecessor of each node
    for (int i=0; i<m; i++) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w);
        pred[to].push_back({from,w});
    }
    for (int i=0;i<n;i++)
        d[i] = oo+1;  // >oo as un-computed
    for (int i=0;i<n;i++)
        p[i] = -oo-1; // <-oo as un-computed
    d[source] = p[source] = 0;
    d[goal] = mind(goal); // can be combined in one pass
    p[goal] = maxd(goal);
    if (d[goal]==oo) printf("No path\nNo path\n");
    else printf("%d\n%d\n", d[goal], p[goal]);
    return 0;
}
