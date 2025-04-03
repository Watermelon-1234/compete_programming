// Grid max weight monotonic path
// top-down dp for checking
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 205
int maxw[N][N]={0}, a[N][N];
bool visit[N][N] ={false};

int dp(int i, int j) {
    if (visit[i][j]) return maxw[i][j];
    if (i==0) return dp(i,j-1) + a[i][j];
    if (j==0) return dp(i-1,j) + a[i][j];
    maxw[i][j]= max(dp(i-1,j), dp(i,j-1)) + a[i][j];
    visit[i][j]=true;
    return maxw[i][j];
}

int main() {
    int m,n;
    scanf("%d%d", &m, &n);
    for (int i=0; i<m; i++) for (int j=0; j<n; j++)
        scanf("%d", &a[i][j]);
    maxw[0][0]=a[0][0];
    visit[0][0]=true;
    printf("%d\n", dp(m-1,n-1));
    return 0;
}
