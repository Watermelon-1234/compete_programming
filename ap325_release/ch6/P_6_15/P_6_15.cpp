// P-6-15 LIS O(nlog(L)), L is the length
#include<bits/stdc++.h>
using namespace std;
#define N 200010
// binary search to find the first >=x
int bsearch(int s[], int n, int x) {
    if (n==0 || s[0]>=x) return 0;
    int po=0;
    for (int jump=n/2; jump>0; jump>>=1) {
        while (po+jump<n && s[po+jump]<x)
            po += jump;
    }
    return po+1;
}
int main() {
    int n;
    scanf("%d",&n);
    int last[N], len=0; // last[i]=the min end of length i+1
    // last will be increasing
    for (int i=0;i<n;i++) {
        int si;
        scanf("%d",&si);
        // one of the next two binary search
        int r = bsearch(last, len, si);
        // only for checking
        int it = lower_bound(last, last+len, si) - last;
        assert(r==it);
        last[r] = si;
        if (r==len) len++;
    }
    printf("%d\n",len);
    return 0;
}
