// P-8-5 arbitrary binary tree, DFS DP
#include <stdio.h>
#define N 200010
int n, w[N]={0}, lc[N], rc[N];
// recursively compute the weight
int find_w(int v) {
    if (v>=n) return w[v]; // leaf
    w[v] = find_w(lc[v]) + find_w(rc[v]);
    return w[v];
}

int main() {
    int m, i, in[110];
    scanf("%d%d", &n, &m);
    for (i=n; i<n*2; i++)
        scanf("%d", &w[i]);
    for (i=0; i<m; i++)
        scanf("%d", &in[i]);
    for (i=0; i<n-1; i++) {
        int v;
        scanf("%d", &v);
        scanf("%d%d", &lc[v], &rc[v]);
    }
    // find initial weight of internal node
    w[1] = find_w(1); // DFS from root=1
    // start simulation
    for (i=0; i<m; i++) {
        int v=1;
        while (v<n) { // until reaching leaf
            if (w[lc[v]] <= w[rc[v]])
                v = lc[v]; // go left
            else v = rc[v]; // go right
            w[v] += in[i];
        }
        if (i>0) printf(" "); // output space
        printf("%d", v);
    }
    printf("\n");
    return 0;
}

