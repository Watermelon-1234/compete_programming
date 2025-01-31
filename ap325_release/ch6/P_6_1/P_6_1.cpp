// P-6-1
#include <bits/stdc++.h>
using namespace std;
#define N 100005
int main() {
    int n;
    int cost[N];
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        scanf("%d", &cost[i]);
    for (int i=3; i<=n; i++)
        cost[i] += min(cost[i-1], cost[i-2]);
    printf("%d\n", cost[n]);
    return 0;
}
