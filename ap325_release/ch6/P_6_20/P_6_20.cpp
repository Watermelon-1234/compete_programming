// P-6-20, hypercube path, top-down
#include <bits/stdc++.h>
using namespace std;
#define N 1000000
int c[N],w[N];

int dp(int goal,int n) {
    if (c[goal]>=0) return c[goal];
    int imax=0;
    // check each bit, find max previous state
    for (int i=0; i<n; i++) {
        if (goal & (1<<i)) { // bit-i=1
            int k = dp(goal ^ (1<<i), n); // set bit-i to 0
            if (k>imax) imax=k;
        }
    }
    c[goal]=imax+w[goal];
    return c[goal];
}

int main() {
	int i,n,m;
    scanf("%d", &n);
    m = 1<<n;
    for (i=0;i<m;i++)
        scanf("%d", &w[i]);
    for (i=0;i<m;i++) c[i] = -1; // not computed
    c[0] = w[0]; // starting point
    printf("%d\n", dp(m-1,n));
    return 0;
}

