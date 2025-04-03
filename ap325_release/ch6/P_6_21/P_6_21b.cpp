// P-6-21, top-down DP, O(n^4), using prefix sum
#include <bits/stdc++.h>
using namespace std;
#define N 60
#define oo 4000
int a[N][N], rsum[N][N],csum[N][N];
int memo[N][N][N][N];
// row cost from column c1 to c2
int row_cost(int r, int c1, int c2) {
    int s=rsum[r][c2]-rsum[r][c1-1];
    return min(s,c2-c1+1-s);
}
// column cost from row r1 to r2
int col_cost(int c, int r1, int r2) {
    int s=csum[r2][c]-csum[r1-1][c];
    return min(s,r2-r1+1-s);
}
// recursively find cost of [left, top, right, bottom]
int dp(int l,int t,int r,int b) {
    if (memo[l][t][r][b]>=0) return memo[l][t][r][b];
    // min-cost of delete a boundary
    int mcost = dp(l, t+1, r, b) + row_cost(t,l,r);
    mcost=min(mcost, dp(l, t, r, b-1) + row_cost(b,l,r));
    mcost=min(mcost, dp(l+1, t, r, b) + col_cost(l,t,b));
    mcost=min(mcost, dp(l, t, r-1, b) + col_cost(r,t,b));
    memo[l][t][r][b]=mcost;
    return mcost;
}

int main() {
    int m,n,i,j;
    scanf("%d%d",&m,&n);
    for (i=1;i<=m;i++) for (j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    int l,t,r,b;
    // prefix sum of row
    for (int row=1;row<=m;row++) {
        rsum[row][0]=0;
        for (int col=1;col<=n;col++)
            rsum[row][col]=rsum[row][col-1]+a[row][col];
    }
    // prefix sum of column
    for (int col=1;col<=n;col++) {
        csum[0][col]=0;
        for (int row=1;row<=m;row++)
            csum[row][col]=csum[row-1][col]+a[row][col];
    }
    // set initial memo
    for (l=1;l<=n;l++) for (r=l;r<=n;r++)
        for (t=1;t<=m;t++) for (b=t;b<=m;b++)
            memo[l][t][r][b] = (r==l || b==t)? 0: -1;
    printf("%d\n",dp(1,1,n,m));
    return 0;
}
