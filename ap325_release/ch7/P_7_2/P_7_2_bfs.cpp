// algorithm bfs
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define N 50010
#define M 2000010
int start[N],wei[N];
vector<int> edge[N];

void readgraph(int n,int m) {
	int i,j,k;
	for (i=0;i<n;i++) scanf("%d",wei+i);
	for (i=0;i<n;i++) edge[i].clear();
	for (i=0;i<m;i++) {
		scanf("%d%d",&j,&k);
        edge[j].push_back(k);
        edge[k].push_back(j);
    }
}

// find total weight of the component containing r
int bfs(int r,int vis[]) {
	queue<int> que;
	int u,total;
	que.push(r); vis[r]=1;
	total=wei[r];
	while (!que.empty()) {
        u=que.front();que.pop();
        for (auto &v: edge[u]) { // each neighbor
            if (vis[v]) continue;
            que.push(v); //printf("%d;",tail);
            vis[v]=1;
            total+=wei[v];
        }
	}
	return total;
}

int main() {
	int ans,i,k,m,n;
	int visit[N];
	scanf("%d %d",&n,&m);//printf("%d: ",n);
	readgraph(n,m);
	//  bfs
	for (i=0;i<n;i++) visit[i]=0;
	ans=0;
	for (i=0;i<n;i++) {
        if (visit[i]) continue;
        k=bfs(i,visit);
        if (k>ans) ans=k;
	}
	printf("%d\n",ans);
	return 0;

}
