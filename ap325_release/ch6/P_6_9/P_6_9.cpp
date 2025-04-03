// 01-knapsack, O(Wn) space
#include <bits/stdc++.h>
using namespace std;
#define N 101
#define W 100005
int d[N][W]={0}; // max price of first i items with <= w weight
int main() {
    int n, total;
    scanf("%d%d", &n, &total);
    int w[N], p[N]; // weight and price
    for (int i=1;i<=n;i++)
        scanf("%d", &w[i]);
    for (int i=1;i<=n;i++)
        scanf("%d", &p[i]);
    for (int i=1; i<=n; i++) {
        for (int j=0;j<w[i]; j++)
            d[i][j]=d[i-1][j]; // i-th item cannot be included
        for (int j=w[i];j<=total;j++) { // choose or not choose
            d[i][j]=max(d[i-1][j-w[i]]+p[i], d[i-1][j]);
        }
    }
    printf("%d\n", d[n][total]);
    return 0;
}
