// P-7-2 max component by find and union;
#include <bits/stdc++.h>
using namespace std;
#define N 50010
int p[N];
// find root
int rfind(int u) {
    if (p[u] < 0) return u;
    return p[u] = rfind(p[u]);
}

int main() {
	int m, n, w[N];
	scanf("%d %d", &n, &m);//printf("%d: ",n);
	for (int i=0; i<n; i++)
        scanf("%d", w+i);
    for (int i=0; i<n; i++)
        p[i] = -1; // parent<0 is a root
	for (int i=0; i<m; i++) { // read an edge and union
        int r1,r2,u,v;
		scanf("%d%d", &u, &v);
		r1 = rfind(u); // root of u
		r2 = rfind(v); // root of v
		if (r1==r2) continue; // same set
		if (p[r1] < p[r2]) {
            p[r1] += p[r2];
            p[r2] = r1;
            w[r1] += w[r2];
		} else {
            p[r2] += p[r1];
            p[r1] = r2;
            w[r2] += w[r1];
		}
    }
    int ans=0;
    for (int i=0; i<n; i++)
        if (p[i]<0 && w[i]>ans)
            ans = w[i];
    printf("%d\n", ans);
	return 0;
}
