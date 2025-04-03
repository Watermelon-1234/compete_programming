// max weight anti-chain, equality is allowed
// O(nlogn) DP
#include <bits/stdc++.h>
using namespace std;
#define N 100010
struct Member {
    int p, c, m;
} seq[N];
// large c first, breaking tie by small m
bool cmp(Member &x, Member &y) {
    if (x.c != y.c) return x.c > y.c;
    return x.m < y.m;
};
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&seq[i].p);
    for (int i=0;i<n;i++)
        scanf("%d",&seq[i].c);
    for (int i=0;i<n;i++)
        scanf("%d",&seq[i].m);
    sort(seq, seq+n, cmp);
    int ans=0;
    // find max weight nondecreasing sequence
    map<int,int> M; // (m, P) largest P with ending m
    M.insert({-1,0}); // as a boundary
    for (int i=0; i<n; i++) {
        auto it = M.upper_bound(seq[i].m);
        it--; // seq[i] can append
        int w=it->second + seq[i].p;
        ans = max(ans,w);
        it = M.insert(it,{seq[i].m,w});
        if (it->second < w) { // when insert fail
            it->second = w;
        }
        // removing larger end but smaller weight
        it++;
        while (it!=M.end() && it->second<= w) {
            it=M.erase(it);
        }
    }
    printf("%d\n",ans);
    auto it=M.end(); it--;
    fprintf(stderr,"%d\n", it->second);
    return 0;
}
