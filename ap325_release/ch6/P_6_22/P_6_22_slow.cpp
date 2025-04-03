// max weight anti-chain, equality is allowed
// O(n^2) DP without monotonic
#include<bits/stdc++.h>
using namespace std;
#define N 100010
struct Member {
    int p, c, m;
} seq[N];
// small c first, breaking tie by large m
bool cmp(Member &x, Member &y) {
    if (x.c != y.c) return x.c < y.c;
    return x.m > y.m;
};
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&seq[i].p);
    for (int i=0;i<n;i++)
        scanf("%d",&seq[i].c);
    for (int i=0;i<n;i++)
        scanf("%d",&seq[i].m);
    sort(seq, seq+n, cmp);
    int dp[N];
    // find max weight nonincreasing sequence
    // dp[i]=seq[i].p + max{dp[j]: seq[j].m>=seq[i].m}
    for (int i=0;i<n;i++) {
        int imax=0;
        for (int j=0; j<i; j++) {
            if (seq[j].m>=seq[i].m)
                imax=max(imax, dp[j]);
        }
        dp[i]=imax+seq[i].p;
    }
    printf("%d\n",*max_element(dp, dp+n));
    return 0;
}
