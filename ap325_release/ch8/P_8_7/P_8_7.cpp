// rooted tree, find a path with max same color
#include<bits/stdc++.h>
using namespace std;
#define N 200010
int n, ans=0, c[N]; // color of node
vector<int> child[N];
map<int,int> D; // a dictionary for id of color
int counter[N]={0}; // counter of each color

void dfs(int v) {
    int cc=D[c[v]]; // find id of color
    counter[cc]++; // add color of v
    ans = max(ans,counter[cc]); // check answer
    for (int u: child[v]) {
        dfs(u);
    }
    counter[cc]--; // recover
    return;
}

int main() {
    int i;
	scanf("%d",&n);
	for (i=0; i<n; i++) scanf("%d",c+i);
	for (i=0; i<n-1; i++) {
        int v,p;
        scanf("%d%d",&p,&v);
        child[p].push_back(v);
	}
	// discretization
	for (i=0;i<n;i++) D.insert({c[i],0});
	int cnt=0; // id of color
	for (auto &v:D) {
        v.second=cnt;
        cnt++;
	}
	dfs(0); // dfs from root
    printf("%d\n",ans);
    return 0;
}

