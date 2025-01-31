#include <bits/stdc++.h>
using namespace std;
#define N 510
int dis[N][N];
queue<pair<int,int>> Q; // visited (i,j)
// push unvisited (i,j) into queue
void enque(int i, int j, int d) {
    if (dis[i][j]>=0) return;
    dis[i][j]=d;
    Q.push({i,j});
    return;
}

int main() {
    char a[N][N];
    int i,j,n,m;
	scanf("%d%d", &m, &n);
    for (i=0; i<m;i++)
        scanf("%s", &a[i][0]);
	for (i=0;i<m;i++) for (j=0;j<n;j++)
        dis[i][j]=-1; // not visited
	Q.push({0,0}); // starting position
	dis[0][0]=0;
	// start BFS
	while (!Q.empty() && dis[m-1][n-1]<0) {
        auto p=Q.front();
        Q.pop();
        int si=p.first, sj=p.second;
        // go down
        for (i=si+1; i<m && a[i][sj]=='0' ; i++)
            enque(i,sj, dis[si][sj]+1);
        for (i=si-1; i>=0 && a[i][sj]=='0' ; i--)
            enque(i,sj, dis[si][sj]+1);
        for (j=sj+1; j<n && a[si][j]=='0' ; j++)
            enque(si,j, dis[si][sj]+1);
        for (j=sj-1; j>=0 && a[si][j]=='0' ; j--)
            enque(si,j, dis[si][sj]+1);
	}
	if (dis[m-1][n-1]>0) dis[m-1][n-1]--;
	printf("%d\n",dis[m-1][n-1]);
    return 0;
}
