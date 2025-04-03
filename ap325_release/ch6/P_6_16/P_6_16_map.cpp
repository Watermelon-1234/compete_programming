// Weighted activity selection problem = independent set for weighted interval graphs
// Using map. overlap at endpoint is not allowed
// dp[i] is the max for interval before right(i), sorted by right
// dp[i]=max{dp[i-1], dp[j]+w[i]}, where j is the max right <left(i)
#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef struct {
    int L,R,W;
} SEG;
SEG seg[N];

// sort by right
bool comp(const SEG p1, const SEG p2) {
    return p1.R < p2.R;
}

int main() {
    int n,i;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
        scanf("%d%d%d", &seg[i].L, &seg[i].R, &seg[i].W);
    sort(seg, seg+n+1, comp); //sort on right
    int dp[N];
    map<int,int> M; // key=right(i), val= dp[i]
    M.insert({-1, dp[0]=0}); // dummy for boundary
    for (i=1; i<=n; i++) {
        auto it = M.lower_bound(seg[i].L);
        it--; // always found, left(i)==right(j) is not allowed
        dp[i] = max(dp[i-1], it->second+seg[i].W);
        // insert dp[i]. careful for the same rights
        it = M.insert(M.begin(),{seg[i].R,dp[i]});
        it->second = max(it->second,dp[i]); // for inserting fails
        //M[seg[i].R] = max( M[seg[i].R], dp[i]); //worse a little
    }
    printf("%d\n",dp[n]);
    return 0;
}

