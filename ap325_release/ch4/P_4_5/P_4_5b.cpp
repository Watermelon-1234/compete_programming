// Q_4_5b greedy, using c++ sort+tuple
//  key of type double t/w, oo for weight 0,
#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define oo 10000.0
int main() {
    int n;
    scanf("%d", &n);
    vector<tuple<double,int,int>> Q;
    for (int i=0; i<n; i++) {
        int t;
        scanf("%d", &t);
        Q.push_back({0,t,0});
    }
    long long total_w=0; // total weight
    for (int i=0; i<n; i++) {
        int w;
        scanf("%d", &w);
        total_w+=w;
        get<2>(Q[i])=w;
        get<0>(Q[i])=(w==0)? oo: (double)get<1>(Q[i])/w;
    }
    sort(Q.begin(), Q.end());
    long long ans=0; // another way to compute
    for (int i=0; i<n; i++) {
        ans += total_w * get<1>(Q[i]);
        total_w -= get<2>(Q[i]);
    }
    printf("%lld\n", ans);
	return 0;
}
