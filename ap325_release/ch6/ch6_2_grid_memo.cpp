//ch6 grid, top-down DP
#include <cstdio>
long long G[100][100]; // as memo
long long grid(int m, int n) {
    if (m==1 || n==1) return 1;
    if (G[m][n]>=0) return G[m][n]; // check memo
    // record before return
    return G[m][n]=grid(m, n-1)+grid(m-1, n);
}
int main() {
    int m,n;
    scanf("%d%d", &m, &n);
    for (int i=0; i<=m; i++)
        for (int j=0; j<=n; j++)
            G[i][j] = -1; // initial unknown
    printf("%lld\n", grid(m,n));
    return 0;
}
