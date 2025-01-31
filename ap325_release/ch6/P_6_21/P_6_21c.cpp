// non-recursive dp O(m^2 * n^2)
#include <cstdio>
#define N 60
#define oo 4000
int a[N][N];
int dp[N][N][N][N]; // record the best for each rectangle
// the cost of boundary line (row,le) to (row,right)
int r_cost(int row, int le, int right) {
    int sum = 0, i;
    for (i=le; i<=right; i++)
        sum += a[row][i];
    i = right - le + 1;
    if (sum<=i/2) return sum;
    return i - sum;
}
// the cost of boundary line (top,col) to (bot,col)
int c_cost(int col, int top, int bot) {
    int sum = 0, i;
    for (i=top; i<=bot; i++)
        sum += a[i][col];
    i = bot - top + 1;
    if (sum<=i/2) return sum;
    return i - sum;
}
int main() {
    int m,n,i,j;
    scanf("%d%d", &m, &n);
    for (i=0;i<m;i++) for (j=0;j<n;j++)
      scanf("%d", &a[i][j]);
    int w, h, top, le; // width, height, top, le
    for (h=1; h<=m; h++) for (w=1; w<=n; w++) {
      // each possible top-le corner
      for (top=0; top+h<=m; top++) for (le=0; le+w<=n; le++) {
        if (w==1 || h==1) {
          dp[h][w][top][le]=0;
          continue;
        }
        int mcost, cost;
        mcost = dp[h-1][w][top+1][le] + r_cost(top,le,le+w-1);
        cost = dp[h-1][w][top][le] + r_cost(top+h-1,le,le+w-1);
        if (cost < mcost) mcost = cost;
        cost = dp[h][w-1][top][le+1] + c_cost(le,top,top+h-1);
        if (cost < mcost) mcost = cost;
        cost = dp[h][w-1][top][le] + c_cost(le+w-1,top,top+h-1);
        if (cost < mcost) mcost = cost;
        dp[h][w][top][le] = mcost;
      }
    }
    printf("%d\n", dp[m][n][0][0]);
    return 0;
}
