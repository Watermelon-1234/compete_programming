// P-6-21, top-down DP, O(m^2 * n^2)
#include <cstdio>
#define N 60
int a[N][N];
int memo[N][N][N][N]; // record the best for each rectangle
// rectangle= [left, top, right, bottom]
int cost(int l,int t,int r,int b) {
    if (memo[l][t][r][b] >= 0) // already computed
        return memo[l][t][r][b];
    int i, mcost, n0, n1, c;
    // top row
    n0 = n1 = 0; // numbers of 0 and 1
    for (i=l; i<=r; i++)
        a[t][i]? n1++ : n0++;
    mcost = cost(l, t+1, r, b) + (n1<n0 ? n1: n0);
    // bottom-row
    n0 = n1 = 0;
    for (i=l; i<=r; i++)
        a[b][i]? n1++ :  n0++; // can also in this way
    c = cost(l, t, r, b-1) + (n1<n0 ? n1: n0);
    if (c<mcost) mcost = c;
    // left-column
    n0 = n1 = 0;
    for (i=t; i<=b; i++)
        a[i][l]? n1++ : n0++;
    c = cost(l+1, t, r, b) + (n1<n0 ? n1: n0);
    if (c<mcost) mcost = c;
    // right column
    n0 = n1 = 0;
    for (i=t; i<=b; i++)
        a[i][r] ?  n1++ : n0++;
    c = cost(l, t, r-1, b) + (n1<n0 ? n1: n0);
    if (c<mcost) mcost = c;
    memo[l][t][r][b] = mcost;
    return mcost;
}

int main() {
    int m,n,i,j;
    scanf("%d%d", &m, &n);
    for (i=0;i<m;i++) for (j=0;j<n;j++)
        scanf("%d", &a[i][j]);
    for (int l=0;l<n;l++) for (int r=l;r<n;r++)
        for (int t=0;t<m;t++) for (int b=t;b<m;b++)
            memo[l][t][r][b] = (r==l || b==t)? 0: -1;
    printf("%d\n", cost(0,0,n-1,m-1));
    return 0;
}
