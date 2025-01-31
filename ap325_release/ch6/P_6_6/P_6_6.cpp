// Grid max weight monotonic path
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 205
int main() {
    int m,n;
    int a[N][N]={0};
    scanf("%d%d", &m, &n);
    for (int i=0; i<m; i++) for (int j=0; j<n; j++)
        scanf("%d", &a[i][j]);
    // first row and first column
    for (int j=1; j<n; j++)
        a[0][j] += a[0][j-1];
    for (int i=1; i<m; i++)
        a[i][0] += a[i-1][0];
    // max of left and up
    for (int i=1; i<m; i++) for (int j=1; j<n; j++)
        a[i][j] += max(a[i-1][j], a[i][j-1]);
    printf("%d\n", a[m-1][n-1]);
    return 0;
}
