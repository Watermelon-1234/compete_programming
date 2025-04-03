// subset product = 1 mod P, O(n*2^(n/2)), using map
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
// recursive generate product of subsets of v[0..i]
// current product=prod, result stored in M
void rec(vector<LL> &v, int i, LL prod, map<LL,LL> &M, LL p) {
    if (i>=v.size()) { // terminal condition
        M[prod] += 1; // insert into map
        return;
    }
    rec(v, i+1, (prod*v[i])%p, M, p); // select v[i]
    rec(v, i+1, prod, M, p); // discard v[i]
    return;
}
// find x^y mod P
LL exp(LL x, LL y, LL p) {
    if (y==0) return 1;
    if (y & 1) return (exp(x, y-1,p)*x)%p;
    // otherwise y is even
    LL t=exp(x, y/2, p);
    return (t*t)%p;
}

int main() {
    int i, n;
    vector<LL> a, b; // input data
    LL p;
    scanf("%d%lld", &n, &p);
    for (i=0;i<n/2;i++) { // half in a
        LL t;
        scanf("%lld", &t);
        a.push_back(t);
    }
    for ( ;i<n;i++) { // half in b
        LL t;
        scanf("%lld", &t);
        b.push_back(t);
    }
    map<LL,LL> M1, M2;
    rec(a,0,1,M1,p); // all subsets of a
    rec(b,0,1,M2,p); // all subsets of b
    M1[1] -= 1; // empty set was counted as product 1
    M2[1] -= 1; // empty set
    LL ans = (M1[1]+M2[1])%p; // the number of 1 in both sides
    // compute 1 cross the two sides
    // for each x in M1, find its inverse in M2
    for (auto e: M1) {
        LL x=e.first, num=e.second;
        LL y = exp(x, p-2, p); // inverse of x
        //printf("%lld, %lld; ",x,y);
        auto it=M2.find(y);
        if (it!=M2.end()) { // found
            ans = (ans + num*it->second)%p;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
