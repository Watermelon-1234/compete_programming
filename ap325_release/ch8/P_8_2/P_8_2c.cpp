// longest distance d(0,v), DFS
#include <bits/stdc++.h>
using namespace std;
#define N 100010
vector<int> child[N]; // child of i
int leng[N]; // length to its parent
int d[N], step[N]; // distance and number of step to v
int longest=0, max_step=0; // answer
void dfs(int v) {
    for (int ch: child[v]) {
        d[ch] = d[v] + leng[ch];
        longest = max(longest, d[ch]);
        step[ch] = step[v] +1;
        max_step = max(max_step, step[ch]);
        dfs(ch);
    }
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=1;i<n;i++) {
        int v, w;
        scanf("%d%d", &v, &w);
        leng[i] = w; // length of edge (i, parent[i])
        child[v].push_back(i);
    }
    d[0]=0, step[0]=0;
    dfs(0); // DFS from root 0
    printf("%d\n%d\n", longest, max_step);
    return 0;
}
