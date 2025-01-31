// Q_4_5 greedy, using c++ sort+struct
#include <bits/stdc++.h>
using namespace std;
struct Item {
    int t,w;
};
bool comp(Item p, Item q) {
    return p.t * q.w < p.w * q.t;
}

int main() {
    int n;
    scanf("%d", &n); assert(n<100000);
    Item Q[N];
    for (int i=0; i<n; i++)
        scanf("%d", &Q[i].t);
    for (int i=0; i<n; i++)
        scanf("%d", &Q[i].w);
    for (int i=0;i<n;i++)
        assert(Q[i].t>0 && Q[i].t<=1000 \
               && Q[i].w>=0 && Q[i].w<=1000);
    sort(Q, Q+n, comp);
    long long ans=0, comp_t=0; // completion time
    for (int i=0; i<n; i++) {
        comp_t += Q[i].t;
        ans += comp_t * Q[i].w;
    }
    printf("%lld\n", ans);
	return 0;
}
