// P_3_9, sliding window, max color of fixed length
#include<bits/stdc++.h>
using namespace std;
#define N 200010
int seq[N], cnt[N]={0}; // counter of color i

int main() {
    int n,L,i;
    scanf("%d%d",&n,&L);
    int n_color=0;
    for (i=0;i<n;i++)
        scanf("%d",&seq[i]);
    // initial window
    for (i=0;i<L;i++) {
        int color=seq[i];
        cnt[color]++;
        if (cnt[color]==1) n_color++;
    }
    int ans=n_color, left;
    // sliding window, seq[i] in, seq[left] out
    for (left=0,i=L; i<n; i++,left++) {
        int color=seq[i];
        cnt[color]++;
        if (cnt[color]==1) n_color++;
        color=seq[left];
        cnt[color]--;
        if (cnt[color]==0) n_color--;
        ans=max(ans,n_color);
    }
    printf("%d\n",ans);
    return 0;
}
