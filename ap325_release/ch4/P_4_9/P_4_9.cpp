// P_4_9 min length R to cover points by k segment of same length
// O(nlogL), L is distance
#include <bits/stdc++.h>
using namespace std;
#define N 50010
int p[N], n, k;
// check if k segment of length r is enough
bool enough(int r) {
    int nseg=k, endline = -1; // current covered range
    for (int i=0; i<n; i++) {
        if (p[i] <= endline) continue;
        if (nseg == 0) return false;
        // use a segment to cover
        nseg--; // remaining segments
        endline = p[i] + r;
    }
    return true;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i=0; i<n; i++)
        scanf("%d", p+i);
	sort(p, p+n);
	// binary search, jump to max not-enough length
	int len = 0, L = p[n-1] - p[0];
	for (int jump=L/2; jump>0; jump>>=1) {
        while (len+jump<L && !enough(len+jump))
            len += jump;
	}
    printf("%d\n", len+1);
	return 0;
}
