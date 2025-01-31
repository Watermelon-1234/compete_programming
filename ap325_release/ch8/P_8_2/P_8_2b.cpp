// longest distance d(0,v), BFS, one pass
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
    vector<int> que; // a queue
    int d[N], step[N], head=0, longest=0, max_step=0;
    d[0]=0, step[0]=0;
    que.push_back(0);
    while (head < que.size()) {
        int v=que[head++];
        for (int ch: child[v]) {
            que.push_back(ch);
            d[ch] = d[v] + leng[ch];
            longest = max(longest, d[ch]);
            step[ch] = step[v] +1;
            max_step = max(max_step, step[ch]);
        }
    }
    assert(que.size()==n); // otherwise not a tree
    printf("%d\n%d\n", longest, max_step);
    return 0;
}
