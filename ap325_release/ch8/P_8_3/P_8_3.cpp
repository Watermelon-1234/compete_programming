// P-8-3 tree median, Bottom-up method, O(n)
#include <bits/stdc++.h>
using namespace std;
#define N 100010

int main() {
    int n, parent[N], leng[N];
    int deg[N]={0}, num[N]={0};
    scanf("%d", &n);
    for (int i=1;i<n;i++) {
        scanf("%d%d", &parent[i], &leng[i]);
        deg[parent[i]]++;
    }
    parent[0]=-1; // root has no parent
    int median=-1;
    long long total=0;
    queue<int> Q;
    for (int i=0; i<n; i++)
        if (deg[i]==0) Q.push(i);
    // bottom-up traversal
    while (!Q.empty()) {
        int v=Q.front();
        Q.pop();
        num[v]++; // add itself
        if (median<0 && num[v]>=(n+1)/2)
            median = v; // first >=n/2 is median
        total += min(num[v], n-num[v]) * leng[v];
        // check parent
        if (parent[v]<0) break; // root
        num[parent[v]] += num[v];
        if (--deg[parent[v]] == 0)
            Q.push(parent[v]);
    }
    printf("%d\n%lld\n", median, total);
    return 0;
}
