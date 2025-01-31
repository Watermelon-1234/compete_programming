// P-6-17 rod-cutting, bottom-up DP O(n^3)
#include <bits/stdc++.h>
using namespace std;
#define N 600
#define oo 99999999

int main() {
    int n,L;
    int p[N]; // points
    int cost[N][N];
    scanf("%d%d", &n, &L);
    for (int i=1; i<=n; i++)
        scanf("%d",&p[i]);
    p[0]=0, p[n+1]=L;
    for (int i=0; i<n+1; i++)
        cost[i][i+1] = 0;
    // len=j-i
    for (int len=2; len<n+2; len++) {
        for (int i=0; i+len<n+2; i++) { // cost(i, i+len)
            int j=i+len, mcost = oo;
            for (int k=i+1; k<j; k++)
                mcost = min(mcost, cost[i][k]+cost[k][j]);
            cost[i][j] = mcost + p[j] - p[i];
        }
    }
    printf("%d\n", cost[0][n+1]);
    return 0;
}

