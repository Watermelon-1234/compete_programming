#include <bits/stdc++.h>
using namespace std;
#define N 102
#define oo 100001

int main() {
    int a[N][N];
    bool visit[N][N]={false};
    int di[4]={0,1,0,-1}, dj[4]={1,0,-1,0};
    int i,j,n,m;
	scanf("%d%d", &m, &n);
	// set boundary to visited
	for (i=0; i<=m+1; i++)
        visit[i][0]=visit[i][n+1]=true;
	for (j=0; j<=n+1; j++)
	    visit[0][j]=visit[m+1][j]=true;
	// read input and find minimal
	int si,sj,imax=oo; // (si,sj) is current position
	for (i=1; i<=m; i++) for (j=1; j<=n; j++) {
        scanf("%d",&a[i][j]);
        if (a[i][j] < imax) {
            si=i, sj=j, imax=a[i][j];
        }
	}
	// start walking
	int total=0;
	while (1) {
        total += a[si][sj]; // goto (si, sj)
        visit[si][sj] = true; // mark visited
        imax = oo;
        for (int dir=0; dir<4; dir++) { // check 4 neighbors
            int ni=si+di[dir], nj=sj+dj[dir];
            if (!visit[ni][nj] && a[ni][nj] < imax)
                i=ni, j=nj, imax=a[ni][nj];
        }
        if (imax == oo) break; // no way to go
        si=i, sj=j;
	}
	printf("%d\n",total);
    return 0;
}
