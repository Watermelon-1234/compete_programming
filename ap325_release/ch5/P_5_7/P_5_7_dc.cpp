// p_5_7 divide and conquer at middle, O(nlogn)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 100010
LL h[N];
// largest rectangle in range [s, t)
LL rect(int s, int t) {
    if (s>=t) return 0;
    if (s+1==t) return h[s];
    int m=(s+t)/2;
    // recursively solve the left and right
    LL max_rect=max(rect(s,m),rect(m+1,t));
    // merge step, find rectangle cross middle
    LL i=m, j=m, height=h[m], largest=0;
    // each time, find maximal [i+1,j-1] of given height
    while (i>=s || j<t) {
        // choosing smaller as the next height
        if (i<s) height=h[j];
        else if (j>=t) height=h[i];
        else height=max(h[i],h[j]);
        // extend the boundary
        while (i>=s && h[i]>=height) // left boundary
            i--;
        while (j<t && h[j]>=height) // right boundary
            j++;
        largest =max(largest, (j-i-1)*height);
    }
    return max(max_rect, largest);
}

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%lld", &h[i]);
    printf("%lld\n",rect(0,n));
    return 0;
}
