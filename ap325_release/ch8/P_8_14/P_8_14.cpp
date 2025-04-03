// unweighted tree diameter, top-down DP
#include <bits/stdc++.h>
using namespace std;
#define N 100010
vector<int> child[N]; // list of children
int hei[N]={0}, diameter=0;
// find longest path whose top-vertex is r
void dfs(int r) {
    for (int v: child[r]) {
        dfs(v);
        diameter = max(diameter, hei[v]+1+hei[r]);
        // update parent's height
        hei[r] = max(hei[r], hei[v]+1);
    }
}

int main() {
	int i,j,k,n;
	bool not_root[N]={false};
	scanf("%d", &n);
	for (i=0; i<n-1; i++) {
		scanf("%d%d",&j,&k);
        child[j].push_back(k);
        not_root[k] = true;
	}
	// find root
	int root=0;
	while (not_root[root]) root++;
	// dfs to find diameter
	dfs(root);
	printf("%d\n",diameter);
	return 0;
}
