// P-6-1, O(1) space
#include <bits/stdc++.h>
using namespace std;
#define N 100005
int main() {
    int n, cost, p=0, pp=0; // previous and pre-previous
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", &cost);
        cost += min(p, pp);
        pp=p;
        p=cost;
    }
    printf("%d\n", cost);
    return 0;
}
