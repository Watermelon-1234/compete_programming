// p_5_7 using stack O(n)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 100010

int main() {
    int n;
    LL h[N];
    h[0]=-1;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lld", &h[i]);
    h[n+1]=0;
    LL largest=0;
    stack<int> inc; // increasing subsequence
    // inc[i]+1 is the left boundary of height inc[i+1]
    inc.push(0); // dummy as left boundary
    for (int i=1;i<=n+1;i++) {
        while (h[inc.top()]>=h[i]) { // when ==, keep the last one
            LL height=h[inc.top()];
            inc.pop();
            largest = max(largest, (i-inc.top()-1)*height);
        }
        inc.push(i);
    }
    printf("%lld\n",largest);
    return 0;
}
