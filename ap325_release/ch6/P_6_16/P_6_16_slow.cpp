// Weighted activity selection problem, O(n^2) method
//  overlap at endpoint is not allowed
// dp[i] is the max for interval until right(i), sorted by right
// dp[i]=max{dp[i-1], dp[j]+w[i]}, where j is the max right <left(i)
#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef struct {
    int L,R,W;
} SEG;
SEG seg[N];
// sort by right, same right points OK since dp[] is increasing
bool comp(const SEG p1, const SEG p2) {
    return p1.R < p2.R;
}

int main() {
    int n, dp[N];
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d%d%d", &seg[i].L, &seg[i].R, &seg[i].W);
    sort(seg,seg+n,comp); //sort by right
    dp[0]=seg[0].W;
    for (int i=1;i<n;i++) {
        // linear search largest j< left[i]
        int j=i-1;
        while (j>=0 && seg[j].R>=seg[i].L)
            j--;
        dp[i] = seg[i].W + ((j<0)? 0 : dp[j]);
        if (dp[i]<dp[i-1]) dp[i]=dp[i-1];
    }
    printf("%d\n",dp[n-1]);
    return 0;
}

