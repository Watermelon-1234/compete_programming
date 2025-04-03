// using lower_bound
#include <bits/stdc++.h>
using namespace std;
#define N 200010
typedef struct {
    int L,R,W;
} SEG;
SEG s[N];
// sort by right, same right points OK since dp[] is increasing
bool comp(const SEG p1, const SEG p2) {
    return p1.R < p2.R;
}
bool cmp2(SEG p, int x) {
    return p.R < x;
}
int main() {
    int n, dp[N];
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d%d%d", &s[i].L, &s[i].R, &s[i].W);
        assert(s[i].L<s[i].R);
    }
    s[0].R = -1; // dummy for boundary
    sort(s, s+n+1, comp); //sort by right
    dp[0] = 0;
    for (int i=1; i<=n; i++) {
        // binary search to find largest j< left[i]
        int j=lower_bound(s, s+i, s[i].L, cmp2) - s;
        dp[i] = dp[j-1] + s[i].W;
        if (dp[i]<dp[i-1]) dp[i] = dp[i-1];
    }
    printf("%d\n",dp[n]);
    return 0;
}

