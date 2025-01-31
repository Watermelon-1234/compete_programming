// P-8-3 tree median, dfs method, O(n)
#include <bits/stdc++.h>
using namespace std;
#define N 100010
vector<pair<int,int>> child[N];
int n, num[N]={0}, median=-1;
long long total=0;
void dfs(int v) {
    for (auto e: child[v]) {
        int u=e.first, w=e.second;
        dfs(u);
        total += min(num[u], n-num[u]) * w;
        num[v] += num[u];
    }
    num[v]++; // add itself
    if (median<0 && num[v]>=(n+1)/2)
        median = v;
    return;
}

int main() {
    scanf("%d", &n);
    for (int i=1;i<n;i++) {
        int v, w;
        scanf("%d%d", &v, &w);
        child[v].push_back({i,w});
    }
    dfs(0);
    printf("%d\n%lld\n", median, total);
    return 0;
}
