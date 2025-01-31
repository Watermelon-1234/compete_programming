// p_5_7 naive O(n2)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 100010

int main() {
    int n;
    LL h[N];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%lld", &h[i]);
    LL largest=0;
    for (int i=0;i<n;i++) { // for each left
        LL pmin=h[i];
        for (int j=i; j<n; j++) {
            pmin=min(pmin,h[j]);
            largest=max(largest, (j-i+1)*pmin);
        }
    }
    printf("%lld\n",largest);
    return 0;
}
