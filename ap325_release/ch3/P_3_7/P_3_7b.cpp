// using p_2_11 O(nlogn)

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int n, k, v;
    LL psum=0;
    scanf("%d%d", &n, &k);
    set<LL> S({0}); // record the prefix_sum
    LL best=0, num=1; // solution of empty range
    for (int r=0; r<n; r++) {
        scanf("%d", &v);
        psum += v; //prefix-sum(r)
        auto it=S.lower_bound(psum-k);
        if (it!=S.end()) {// found
            LL t=psum-*it;
            if (t>best)
                best=t, num=1;
            else if (t==best) num++;
        }
        S.insert(psum); // insert prefix-sum(r)
    }
    printf("%lld\n%lld\n",best,num);
    return 0;
}



