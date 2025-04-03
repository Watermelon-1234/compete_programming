// bottom-up DP
#include <stdio.h>
#define N 200010

int w[N],in[110];
int lc[N],rc[N]; // left and right child
int p[N]; // parent

int main() {
    int n, m, i;
    scanf("%d%d", &n, &m);
    for (i=n; i<n*2; i++)
        scanf("%d", w+i);
    for (i=0; i<m; i++)
        scanf("%d", in+i);
    p[1] = -1; // root has no parent
    for (i=0; i<n-1; i++) {
        int s, l, r;
        scanf("%d%d%d", &s, &l, &r);
        lc[s] = l, rc[s] = r;
        p[r] = p[l] = s;
    }
    int deg[N]; // num of children
    for (i=1; i<n; i++) deg[i] = 2; // each has two children
    // find weight of internal nodes
    for (i=1; i<n; i++) w[i] = 0;
    // start a bottom-up traversal
    int que[N], head=0, tail=0; // FIFO queue
    for (i=n; i<2*n; i++) // push all leaves
        que[tail++] = i;
    while (head < tail) { // while queue is not empty
        int v=que[head++]; // pop to v
        if (v==1) break; // root
        int u=p[v];
        w[u] += w[v];
        // if u has no child, then push u
        deg[u]--;
        if (deg[u]==0) que[tail++] = u;
    }
    // start simulation
    for (i=0; i<m; i++) { // each incoming
        int v=1;
        while (v<n) {
            if (w[lc[v]] <= w[rc[v]])
                v = lc[v];
            else v=rc[v];
            w[v] += in[i];
        }
        if (i>0) printf(" ");
        printf("%d",v);
    }
    printf("\n");
    return 0;
}

