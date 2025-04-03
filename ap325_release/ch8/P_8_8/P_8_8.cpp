// P-8-8 unweighted max independent set of a tree
// top-down implement
#include <bits/stdc++.h>
using namespace std;

#define N 100020
vector<int> child[N];
int parent[N], chosen[N]; // if chosen
// return max independent set, un-chosen its parent if chosen
int dfs(int r) {
    int num=0;
    for (int s:child[r]) {
        num += dfs(s);
    }
    if (chosen[r]) { // r is chosen
        chosen[parent[r]] = 0; // un-chosen its parent
        return num + 1;
    }
    return num; // r is not chosen
}

int main() {
    int i, n;
	scanf("%d",&n);
	for (i=1; i<n; i++) scanf("%d",&parent[i]);
	for (i=1; i<n; i++)
        child[parent[i]].push_back(i);
    for (i=0; i<n; i++) chosen[i]=1;
    parent[0] = n; // dummy
	printf("%d\n", dfs(0)); // root = 0
    return 0;
}
