// Tree, Max weight independent set, top-down DP
#include <bits/stdc++.h>
using namespace std;
#define N 100010
int f0[N],f1[N],w[N];
vector<int> child[N];

void dfs(int r) {
    f0[r]=0;
    f1[r]=w[r];
    for (int c:child[r]) {
        dfs(c);
        f0[r]+=max(f0[c],f1[c]);
        f1[r]+=f0[c];
    }
    return;
}

int main() {
    int parent,n;
    scanf("%d%d",&n,&w[1]);
    for (int i=1;i<=n;i++) child[i].clear();
    for (int i=2;i<=n;i++) {
        scanf("%d%d",&parent,&w[i]);
        child[parent].push_back(i);
    }
    dfs(1);
    printf("%d\n",max(f0[1],f1[1]));
    return 0;
}
