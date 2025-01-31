// fake solution, find max color and search
#include<bits/stdc++.h>
using namespace std;
#define N 200010

typedef long long LL;
int n;
int c[N];
vector<int> child[N];
map<int,int> D;

// max num of nodes of color col in a path
int dfs(int v, int col) {
    int nc = 0;
    for (int u: child[v]) {
        nc = max(nc, dfs(u,col));
    }
    return nc + (c[v]==col);
}

int main() {
    int i,t;
	scanf("%d",&n); //printf("n=%d\n",n);//assert(n<=100000);
	for (i=0;i<n;i++) scanf("%d",c+i);
	for (i=0;i<n-1;i++) {
        int v,p;
        scanf("%d%d",&p,&v);
        child[p].push_back(v);
	}
	// discretization
	for (i=0;i<n;i++)
        D[c[i]] += 1;
	int cnt=0, col=-1;
	for (auto &v:D) {
        if (v.second>cnt)
            cnt=v.second, col=v.first;
	}
	fprintf(stderr,"max col= %d, total num= %d, ", col,cnt);
	cnt = dfs(0, col);
	fprintf(stderr,"WA = %d\n", cnt);
    printf("%d\n", cnt);
    return 0;
}

