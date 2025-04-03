// P-8-8 unweighted max independent set of a tree
// greedy, choosing leaf and mark its parent
// bottom-up implement
#include <bits/stdc++.h>
using namespace std;
#define N 100020
int parent[N], deg[N]={0};

int main() {
    int i, n, total=0;
	scanf("%d",&n);
	for (i=1;i<n;i++) {
        scanf("%d",&parent[i]);
        deg[parent[i]]++;
	}
    int mark[N]={0}; // cannot be chosen
    // bottom-up traversal
    queue<int> que;
	for (i=0;i<n;i++)
        if (deg[i]==0) que.push(i);
    i=0;
	while (! que.empty()) {
        int v=que.front();
        que.pop(); i++;
        if (v==0) break;
        if (mark[v] == 0) {
            total++;
            mark[parent[v]] = 1;
        }
        if (--deg[parent[v]] == 0)
            que.push(parent[v]);
	}
    if (mark[0]==0) total++; // if root is chosen
	printf("%d\n",total);
	fprintf(stderr," visited nodes =%d\n",i);
    return 0;
}
