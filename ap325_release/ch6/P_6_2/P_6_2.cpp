// max independent on array
#include <bits/stdc++.h>
using namespace std;
#define N 100005
int main() {
    int n;
    int p[N];
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &p[i]);
    int dp[N]; // dp[i] = the max until i
    dp[0]=p[0], dp[1]=max(p[0], p[1]);
    for (int i=2; i<n; i++)
        dp[i] = max(dp[i-1], dp[i-2]+p[i]);
    printf("%d\n", dp[n-1]);
    return 0;
}
