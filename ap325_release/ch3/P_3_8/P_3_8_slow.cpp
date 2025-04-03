// P3-8, O(NL) naive method
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
int seq[MAXN];

int main() {
    int n, L, i,j;
    scanf("%d%d\n", &n, &L);
    for (i=0; i<n; i++) {
        scanf("%d",&seq[i]);
    }
    int max_diff=0;
    for (i=0; i<=n-L; i++) {
        int mmax=seq[i],mmin=seq[i];
        for (int j=i+1; j<i+L; j++)
            mmax=max(mmax,seq[j]), mmin=min(mmin,seq[j]);
        max_diff=max(max_diff, mmax-mmin);
    }
    printf("%d\n",max_diff);
    return 0;
}
