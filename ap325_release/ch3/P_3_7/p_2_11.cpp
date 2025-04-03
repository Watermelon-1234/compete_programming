// p_2_11

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, psum=0, k, v;
    scanf("%d%d", &n, &k);
    set<int> S({0}); // record the prefix_sum
    int best=0; // solution of empty range
    for (int r=0; r<n; r++) {
        scanf("%d", &v);
        psum += v; //prefix-sum(r)
        auto it=S.lower_bound(psum-k);
        if (it!=S.end()) // found
            best=max(best, psum-*it); //currently best
        S.insert(psum); // insert prefix-sum(r)
    }
    printf("%d\n",best);
    return 0;
}



