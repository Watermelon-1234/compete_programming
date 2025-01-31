// Tree, Max weight independent set, top-down DP
#include <bits/stdc++.h>
using namespace std;
#define N 100010
int f[N],w[N];
vector<int> child[N], child2[N];

void dfs(int r) {
    int sum1=w[r], sum0=0;
    for (int c:child[r]) {
        dfs(c);
        sum0 += f[c];
    }
    for (int c:child2[r])
        sum1+=f[c];
    f[r] = max(sum0, sum1);
    return;
}

int main() {
    int parent,n;
    scanf("%d%d",&n,&w[1]);
    for (int i=2;i<=n;i++) {
        scanf("%d%d",&parent,&w[i]);
        child[parent].push_back(i);
    }
    // find grandchild
    for (int i=1; i<=n; i++) {
        for (int v: child[i]) {
            child2[i].insert(child2[i].end(), child[v].begin(),child[v].end());
        }
    }
    dfs(1);
    printf("%d\n",f[1]);
    return 0;
}
