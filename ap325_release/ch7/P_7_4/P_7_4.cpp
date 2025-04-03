// P-7-4 minimum turn
#include <bits/stdc++.h>
using namespace std;
#define N 510
#define oo 1000000

int main() {
    char a[N][N]; // chessboard
    int dis[N][N]; // min distance(turn)
    int di[4]={0,1,0,-1}, dj[4]={1,0,-1,0};
    int i,j,n,m;
	scanf("%d%d", &m, &n);
	// set boundary
	for (i=0; i<=m+1; i++)
        a[i][0]=a[i][n+1]='1';
	for (j=0; j<=n+1; j++)
	    a[0][j]=a[m+1][j]='1';
    for (i=1; i<=m;i++)
        scanf("%s", &a[i][1]);
	for (i=1;i<=m;i++) for (j=1;j<=n;j++)
        dis[i][j]=-1; // not visited
	queue<pair<int,int>> Q; // visited (i,j)
	Q.push({1,1}); // starting position
	dis[1][1]=0;
	// start BFS
	while (!Q.empty() && dis[m][n]<0) {
        auto p=Q.front();
        Q.pop();
        int si=p.first, sj=p.second;
        for (int dir=0; dir<4; dir++) { // 4 directions
            int ni=si+di[dir], nj=sj+dj[dir];
            while (a[ni][nj]=='0') { // until touch 1
                if (dis[ni][nj]==-1) { // not visited
                    dis[ni][nj]=dis[si][sj]+1;
                    Q.push({ni,nj});
                }
                ni+=di[dir];
                nj+=dj[dir];
            }
        }
	}
	if (dis[m][n]>0) dis[m][n]--; // count one more
	printf("%d\n",dis[m][n]);
    return 0;
}
