#include <bits/stdc++.h>
using namespace std;
struct P {
    int pmin, pmax;
};
// range [s, t)
P f(int A[], int s, int t) {
    if (s+1==t) return {A[s],A[s]};
    int m=(s+t)/2;
    P le=f(A,s,m), ri=f(A,m,t);
    return {min(le.pmin, ri.pmin), max(le.pmax, ri.pmax)};
}

int main() {
    int a[10]={3, 0, 7, -3, -10, 5, 1, 7, 6, -2};
    P x=f(a,0,10);
    printf("%d\n%d\n",x.pmin, x.pmax);
    return 0;
}
