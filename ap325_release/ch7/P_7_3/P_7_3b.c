#include <stdio.h>
#define N 102
#define oo 100001

int main() {
    int a[N][N], visit[N][N]={{0}};
    int i,j,n,m;
	scanf("%d%d",&m,&n);
	int si,sj,mm=oo; // minimal and its position
	// read input and find minimal
	for (i=0; i<m; i++) for (j=0;j<n;j++) {
        scanf("%d", &a[i][j]);
        if (a[i][j]<mm) {
            si=i, sj=j, mm=a[i][j];
        }
	}
	// start
	int total=0;
	while (1) { // repeat until no way
        total += a[si][sj];
        visit[si][sj] = 1; // visited set to oo
        // find the minimal neighbor
        mm = oo;
        if (si>0 && visit[si-1][sj]==0 && a[si-1][sj]<mm)
            i=si-1, j=sj, mm=a[si-1][sj];
        if (si<m-1 && visit[si+1][sj]==0 && a[si+1][sj]<mm)
            i=si+1, j=sj, mm=a[si+1][sj];
        if (sj>0 && visit[si][sj-1]==0 && a[si][sj-1]<mm)
            i=si, j=sj-1, mm=a[si][sj-1];
        if (sj<n-1 && visit[si][sj+1]==0 && a[si][sj+1]<mm)
            i=si, j=sj+1, mm=a[si][sj+1];
        if (mm == oo) break; // no way to go
        si = i, sj = j;
	}
	printf("%d\n",total);
    return 0;
}

