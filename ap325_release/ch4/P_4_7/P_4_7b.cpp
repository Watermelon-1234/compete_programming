// P_4_7 greedy, using multiset
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    int n;
    scanf("%d", &n);
    multiset<LL> S;
    for (int i=0; i<n; i++) {
        int m;
        scanf("%d", &m);
        S.insert((LL)m);
    }
    LL cost=0; // total cost
    for (int i=0; i<n-1; i++) { // merge n-1 times
        // merge the smallest two sets
        LL m=*S.begin();
        S.erase(S.begin());
        m += *S.begin();
        S.erase(S.begin());
        S.insert(m);
        cost += m;
    }
    assert(S.size()==1);
    printf("%lld\n%lld\n", *S.begin(), cost);
	return 0;
}
