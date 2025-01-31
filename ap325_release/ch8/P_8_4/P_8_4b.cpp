// tree height, top-down DP, O(n)
#include <bits/stdc++.h>
using namespace std;
#define N 100010
int height[N];  // height of node i
vector<int> child[N]; // children of node i
// top-dowm memo DP to find height of r
int findh(int r) {
    if (height[r]>=0) return height[r];
    height[r]=0;
    for (int v: child[r])
        height[r] = max(height[r], findh(v)+1); // recursive call
    return height[r];
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
    int total_h = 0;
    for (int i=1; i<=n; i++)
        height[i]=-1;  // not computed
    for (i=1; i<=n; i++)
        total_h += findh(i);
    printf("%d\n%d\n", root, total_h);
	return 0;
}
