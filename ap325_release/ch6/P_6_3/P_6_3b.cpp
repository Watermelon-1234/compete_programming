// min dominating cost on array
// dp0[i] = min cost of [0..i] without choosing i
// dp1[i] = min cost of [0..i] with choosing i
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005
#define oo 1000000000
int main() {
    int n, c[N];
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &c[i]);
    int dp0[N], dp1[N];
    dp0[0]=oo, dp1[0]=c[0];
    dp0[1]=c[0], dp1[1]=c[1];
    for (int i=2; i<n; i++) {
        dp0[i] = dp1[i-1]; // not choosing i, i-1 must be chosen
        // i is chosen, i-2 need dominating, but may be by i-1
        dp1[i] = c[i]+ min(min(dp0[i-2],dp1[i-2]),dp1[i-1]);
    }
    printf("%d\n", min(dp0[n-1],dp1[n-1]));
    return 0;
}
