// P-7-10 components in matrix, transform to 1d
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 510
char a[N][N]={0}; // a 0/1 matrix
// a cell (i,j) is indexed by i*(n+2)+j
int p[N][N];// parent
int di[4]={0,1,0,-1}, dj[4]={1, 0,-1,0};  // index difference
int n_area=0, max_area=0;
int bfs(int i, int j, int root) {
    p[i][j]=root;
    int cnt=0;
    queue<pair<int,int>> Q;
    Q.push({i,j});
    while (!Q.empty()) {
        i=Q.front().first;
        j=Q.front().second;
        cnt++;
        Q.pop();
        for (int dir=0;dir<4;dir++) {
            int ni=i+di[dir], nj=j+dj[dir];
            if (a[ni][nj]==1 && p[ni][nj]!=root) {
                p[ni][nj]=root;
                Q.push({ni,nj});
            }
        }
    }
    return cnt;
}
int main() {
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);//printf("%d: ",n);
	for (int i=0; i<=m+1; i++) for (int j=0;j<=n+1;j++) {
        p[i][j] = -1; // parent<0 is a root
	}
	for (int i=1; i<=m; i++) for (int j=1;j<=n;j++) {
        scanf("%d", &a[i][j]);
    }
    // bfs for component
	for (int i=1; i<=m; i++) for (int j=1;j<=n;j++) {
        if (a[i][j]==1 && p[i][j]==-1) { // -1 is unvisited
            n_area++;
            max_area=max(max_area, bfs(i,j,i*N+j));
        }
    }
    LL total_n=n_area, total_max=max_area;
    //fprintf(stderr,"max=%d, n=%d\n", total_max, total_n);
    while (k--) { // read an cell
        int i, j, v;
		scanf("%d%d", &i, &j);
		if (a[i][j]==1) continue;
		a[i][j]=1;
		p[i][j]=i*N+j;
		n_area++;
		int temp[4];
		for (int dir=0; dir<4; dir++) {
            temp[dir] = p[i+di[dir]][j+dj[dir]];
		}
		sort(temp, temp+4);
		//for (int t=0;t<4;t++) fprintf(stderr,"%d ",temp[t]); fprintf(stderr,"\n");
		if (temp[0]>=0) n_area--;
		for (int t=1;t<4;t++)
            if (temp[t]>=0 && temp[t]!=temp[t-1])
                n_area--;
		max_area=max(max_area, bfs(i,j,p[i][j]));
		total_n += n_area;
		total_max += max_area;
    //fprintf(stderr,"max=%d, n=%d\n", max_area, n_area);
    }
    printf("%lld\n%lld\n", total_max, total_n);
	return 0;
}
