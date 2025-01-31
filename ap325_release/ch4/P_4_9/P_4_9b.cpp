// P_4_9 min length R to cover points by k segment of same length
// O(nlogL), L is distance
#include <bits/stdc++.h>
using namespace std;
#define N 50010

// check if k segment of length x is enough
bool check(int p[], int n, int k, int x) {
    int endline = -1; // current covered range
    for (int i=0; i<n; i++) {
        if (p[i] <= endline) continue;
        if (k == 0) return false;
        // use a segment to cover
        k--;
        endline = p[i] + x;
    }
    return true;
}

int main() {
    int n, i, k, p[N];
	scanf("%d%d", &n, &k);
	for (i=0; i<n; i++)
        scanf("%d", p+i);
	sort(p, p+n);
	// lower and upper bound of diameter
	int low = 1, up = p[n-1] - p[0];
	while (low < up) {
        int diameter = (low+up)>>1;
        if (!check(p, n, k, diameter))
            low = diameter+1; // too short
        else // long enough
            up = diameter;
	}
    printf("%d\n", low);
	return 0;
}
