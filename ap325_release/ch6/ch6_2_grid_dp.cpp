//ch6 grid, DP
#include <cstdio>
int main() {
    long long G[50][50];
    int m,n;
    scanf("%d%d", &m, &n);
    for (int i=1; i<=m; i++)
        G[i][1]=1;
    for (int j=1; j<=n; j++)
        G[1][j]=1;
    for (int i=2; i<=m; i++)
        for (int j=2; j<=n; j++)
            G[i][j] = G[i-1][j] + G[i][j-1];
    printf("%lld\n", G[m][n]);
    return 0;
}
