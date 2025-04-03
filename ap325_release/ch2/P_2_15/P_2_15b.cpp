// P-2-15, using extended array and lower_bound
#include <bits/stdc++.h>
using namespace std;
#define N 500010
int p[N];

int main() {
    int i, n, m;
	scanf("%d%d",&n, &m);
	for (i=0; i<n; i++)
        scanf("%d", &p[i]);
    for (i=0; i<n; i++) // double array
        p[n+i] = p[i];
    // prefix sum
	for (i=1; i<2*n; i++)
        p[i] += p[i-1];
	int room=0, q;
	for (i=0; i<m; i++) {
        scanf("%d", &q);
        if (room != 0) // desired prefix-sum
            q += p[room-1];
        // binary search the first >= q
        room = lower_bound(p+room, p+2*n, q) - p;
        room = (room+1)%n; // adjust
	}
	printf("%d\n",room);
    return 0;
}
