// P-6-13 min cost of k-domination, using PQ
// p[i]= min cost to cover [1..i] and choosing i
// p[i] = c[i]+min{p[j]: j>i-2k-2}; and p[i]=c[i] for i<=k+1
#include <bits/stdc++.h>
using namespace std;
#define N 200005
int main() {
    int n,k, c[N], p[N];
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; i++)
        scanf("%d", &c[i]);
    priority_queue<pair<int,int>> pq; // (-p[i], i)
    p[1]=c[1];
    pq.push({-p[1],1});
    for (int i=2; i<=n; i++) {
        if (i<=k+1)
            p[i]=c[i];
        else {
            // remove out-of-range minimum
            while (pq.top().second<i-2*k-1)
                pq.pop();
            p[i] = -pq.top().first + c[i];
        }
        pq.push({-p[i],i});
    }
    printf("%d\n", *min_element(p+n-k, p+n+1));
    return 0;
}
