// min dominating cost on array
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005
int main() {
    int n, c[N];
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &c[i]);
    int dp[N]; // dp[i] = the min c until i and include i
    dp[0]=c[0], dp[1]=c[1];
    dp[2]=c[2]+min(dp[0],dp[1]);
    // the last one must be at i-3, i-2, or i-1
    for (int i=3; i<n; i++)
        dp[i] = c[i] + min(min(dp[i-3],dp[i-2]),dp[i-1]);
    printf("%d\n", min(dp[n-2],dp[n-1]));
    return 0;
}
