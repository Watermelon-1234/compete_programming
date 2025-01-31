// longest distance d(0,v), BFS, two pass
#include <bits/stdc++.h>
using namespace std;
#define N 100010
vector<int> child[N]; // child of i
int parent[N], leng[N];
int main() {
    int n;
    scanf("%d", &n);
    for (int i=1;i<n;i++) {
        int v, w;
        scanf("%d%d", &v, &w);
        parent[i]=v;
        leng[i] = w; // length of edge (i, parent[i])
        child[v].push_back(i);
    }
    // find a top-down sequence
    vector<int> que;
    int head=0; // a queue
    que.push_back(0);
    while (head < que.size()) {
        int v=que[head++];
        for (int ch: child[v])
            que.push_back(ch);
    }
    assert(que.size()==n); // otherwise not a tree
    //  compute distance in top-down sequence
    int d[N];
    d[0]=0;
    for (int i=1; i<n; i++) {
        int v = que[i];
        d[v] = d[parent[v]] + leng[v];
    }
    printf("%d\n", *max_element(d, d+n));
    // compute max step, using range-based for
    for (int v: que) {
        if (v>0) // 0 has no parent
            d[v] = d[parent[v]] + 1;
    }
    printf("%d\n", *max_element(d, d+n));
    return 0;
}
