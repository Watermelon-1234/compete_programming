// P-6-15 LIS O(nL), L is the length, linear search
#include <bits/stdc++.h>
using namespace std;
#define N 200010

int main() {
    int n;
    scanf("%d",&n);
    int last[N], len=0; // last[i]=the min end of length i+1
    // last will be increasing
    for (int i=0; i<n; i++) {
        int si;
        scanf("%d", &si);
        int r = 0;
        // find the max last[r] < t
        while (r<len && last[r]<si)
            r++;
        last[r] = si;
        if (r==len) len++;
    }
    printf("%d\n", len);
    return 0;
}
