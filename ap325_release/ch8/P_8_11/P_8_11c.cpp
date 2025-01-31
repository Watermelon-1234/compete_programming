// Tree, Max weight independent set, bottom-up DP
#include <bits/stdc++.h>
using namespace std;
#define N 100010
// f0[], f1[]: opt without/with root
// f0[r]=sum(max(f0[v],f1[v])), f1[r]=w[r]+sum(f0[v])
int main() {
    int parent[N],n, f0[N]={0}, f1[N], deg[N]={0};
    scanf("%d%d",&n,&f1[1]);
    for (int i=2;i<=n;i++) {
        scanf("%d%d",&parent[i],&f1[i]); // weight[i] in f1[i]
        deg[parent[i]]++;
    }
    queue<int> Q;
    for (int i=1; i<=n; i++)
        if (deg[i]==0) Q.push(i);
    while (!Q.empty()) {
        int v=Q.front();
        Q.pop();
        if (v==1) break;
        int r=parent[v];
        f0[r] += max(f0[v],f1[v]);
        f1[r] += f0[v];
        if (--deg[r] == 0) Q.push(r);
    }
    printf("%d\n",max(f0[1],f1[1]));
    return 0;
}
