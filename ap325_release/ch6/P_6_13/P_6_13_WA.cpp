// P-6-13 min cost of k-domination, greedy method
// should be wrong answer
// pick as small as possible until distance constraint
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
    int last=min(k+1,n), total=0, i=1;
    while (i <=n) {
        int pick=i;
        while (i<=last) {
            if (c[i]<=c[pick]) pick=i;
            i++;
        }
        total+=c[pick];
        if (pick>=n-k) break;
        i=pick+k+1;
        last=min(pick+2*k+1, n);
    }
    printf("%d\n", total);
    return 0;
}
