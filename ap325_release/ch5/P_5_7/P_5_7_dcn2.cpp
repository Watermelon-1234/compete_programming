// p_5_7 divide and conquer at smallest, O(n^2)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 100010
LL h[N];
// largest rectangle in range [s, t)
LL rect(int s, int t) {
    if (s>=t) return 0;
    if (s+1==t) return h[s];
    // find min height
    int m=min_element(h+s, h+t) - h;
    LL max_rect=(t-s)*h[m];
    // recursively solve the left and right
    max_rect=max(max_rect, rect(s,m));
    max_rect=max(max_rect, rect(m+1,t));
    return max_rect;
}

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%lld", &h[i]);
    printf("%lld\n",rect(0,n));
    return 0;
}
