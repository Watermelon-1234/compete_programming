// Q_4_7 greedy, slow method using array
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 400010
int main() {
    int n;
    LL m[N];
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%lld", &m[i]);
    }
    sort(m,m+n);
    LL left=0, right=n-1, cost=0; // [left, right]=current data
    // merge, n reduced by 1 each time
    for ( ; n>1; n--) {
        // merge the smallest two sets
        LL x=m[left]+m[left+1];
        cost += x;
        // delete 0 and 1, insert x
        int j=right;
        left += 2; // delete two smallest
        while (j>=left && m[j]>x) { // find position
            m[j+1]=m[j];
            j--;
        }
        m[j+1]=x; // insert x
        right++;
    }
    printf("%lld\n%lld\n", m[left], cost);
	return 0;
}
