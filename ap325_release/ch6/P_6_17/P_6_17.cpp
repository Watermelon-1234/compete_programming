// P-6-17 rod-cutting, top-down DP O(n^3)
#include <bits/stdc++.h>
using namespace std;
#define N 600
#define oo 99999999
int p[N]; // points
int memo[N][N];
// min cost of [i,j]
int cost(int i, int j) {
    if (memo[i][j]>=0) return memo[i][j];
    int mincost = oo;
    for (int k=i+1; k<j; k++)
        mincost = min( mincost, cost(i,k) + cost(k,j));
    mincost += p[j] - p[i];
    return memo[i][j]=mincost;
}

int main() {
    int n,L;
    scanf("%d%d", &n, &L);
    for (int i=1; i<=n; i++)
        scanf("%d",&p[i]);
    p[0]=0, p[n+1]=L;
    for (int i=0;i<n+2;i++)
        for (int j=i+1;j<n+2;j++)
            memo[i][j]=-1;
    for (int i=0; i<n+1; i++)
        memo[i][i+1] = 0;
    printf("%d\n", cost(0,n+1));
    return 0;
}

