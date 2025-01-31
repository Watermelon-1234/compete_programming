// P-6-17 rod-cutting, WA, cutting at median
#include <bits/stdc++.h>
using namespace std;
#define N 600
#define oo 99999999
int p[N]; // points
// min cost of [i,j]
int cost(int i, int j) {
    if (j<=i+1) return 0;
    int k = (i+j)/2;
    int mincost = cost(i,k) + cost(k,j) + p[j] - p[i];
    return mincost;
}

int main() {
    int n,L;
    scanf("%d%d", &n, &L);
    for (int i=1; i<=n; i++)
        scanf("%d",&p[i]);
    p[0]=0, p[n+1]=L;
    printf("%d\n", cost(0,n+1));
    return 0;
}

