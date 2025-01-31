// tree height, dfs version, using vector
#include <bits/stdc++.h>
using namespace std;
#define N 100010
int height[N];  // height of node i
vector<int> child[N]; // children of node i
// recursively find height of r
void findh(int r) {
    height[r] = 0;
    for (int v: child[r]) {
        findh(v); // recursive call
        height[r] = max(height[r], height[v]+1);
    }
}

int main() {
	int i, j, n, root;
    int parent[N]={0};  // parent of node i
    scanf("%d", &n);
    for (i=1; i<=n; i++) {
        int deg, ch;
        scanf("%d", &deg);
        for (j=0; j<deg; j++) {
            scanf("%d", &ch);
            child[i].push_back(ch);
            parent[ch] = i;
        }
    }
    // find root, the node without parent
    for (root=1; root<=n; root++)
        if (parent[root] == 0) break;
    findh(root);
    int total_h = 0;
    for (i=1; i<=n; i++) total_h += height[i];
    printf("%d\n%d\n", root, total_h);
	return 0;
}
