// P-6-13 min cost of k-domination, naive O(kn) method
// p[i]= min cost to cover [1..i] and choosing i
// p[i] = c[i]+min{p[j]: j>i-2k-2}; and p[i]=c[i] for i<=k+1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200005
int main() {
    int n,k;
    int c[N];
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; i++)
        scanf("%d", &c[i]);
    int p[N];
    for (int i=1; i<=n; i++) {
        if (i<=k+1)
            p[i]=c[i];
        else {
            int minp=*min_element(p+max(1,i-2*k-1), p+i);
            p[i] = minp + c[i];
        }
    }
    printf("%d\n", *min_element(p+n-k, p+n+1));
    return 0;
}
