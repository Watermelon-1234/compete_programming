// P-7-10 components in matrix, transform to 1d
// a cell (i,j) is indexed by i*(n+2)+j
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 510
char a[N*N]={0}; // a 0/1 matrix
int p[N*N], di[4]={1,-1}; // parent and index difference
int n_area=0, max_area=0;
// find root
int rfind(int u) {
    if (p[u] < 0) return u;
    return p[u] = rfind(p[u]);
}
// find component, return size
int dfs(int v, int root) {
    p[v]=root;
    int cnt=1;
    for (int dir=0;dir<4;dir++) {
        int u=v+di[dir];
        if (a[u] && p[u]==-1)
            cnt += dfs(u, root);
    }
    return cnt;
}
// combine two area, p[] = -size
void combine(int u,int v) {
    int r1 = rfind(u); // root of u
    int r2 = rfind(v); // root of v
    if (r1==r2) return; // same set
    max_area=max(max_area, -p[r1]-p[r2]);
    n_area--;
    if (p[r1] < p[r2]) {
        p[r1] += p[r2];
        p[r2] = r1;
    } else {
        p[r2] += p[r1];
        p[r1] = r2;
    }
    return;
}
int main() {
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);
	for (int i=1; i<=m; i++) for (int j=1;j<=n;j++) {
        p[i*(n+2)+j] = -1; // parent<0 is a root
	}
	for (int i=1; i<=m; i++) for (int j=1;j<=n;j++) {
        scanf("%d", &a[i*(n+2)+j]);
    }
    n+=2;
    di[2]=n, di[3]=-n; // next row and previous row
    int mn=(m+1)*n;
    // dfs for component
	for (int v=n; v<mn; v++) {
        if (a[v] && p[v]==-1) { // -1 is unvisited
            p[v] = - dfs(v, v);
            n_area++;
            max_area=max(max_area, -p[v]);
        }
    }
    LL total_n=n_area, total_max=max_area;
    //printf("%d %d\n", total_max, total_n);
    while (k--) { // read an cell
        int i, j, v;
		scanf("%d%d", &i, &j);
		assert(i<=m && j<=n);
		v=i*n+j;
		if (a[v]==1) continue; // already 1, do nothing
		a[v]=1; // set to 1
		n_area++;
		max_area=max(max_area, 1);
		// try to combine 4 neighbors
		for (i=0; i<4; i++) {
            if (a[v+di[i]]==0) continue;
            combine(v, v+di[i]);
		}
		total_n += n_area;
		total_max += max_area;
    }
    printf("%lld\n%lld\n", total_max, total_n);
	return 0;
}
