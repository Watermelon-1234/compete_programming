// tree height bottom-up dp, using STL queue
#include <bits/stdc++.h>
using namespace std;
#define N 100010

int main() {
    int parent[N]={0};  // parent of node i
    int h[N]={0};  // height of node i
    int deg[N]; // num of children
    queue<int> Q;
    int n, i, j, ch;
    scanf("%d", &n);
    for (i=1; i<=n; i++) {
        scanf("%d", &deg[i]);
        if (deg[i] == 0) Q.push(i);
        for (j=0; j<deg[i]; j++) {
            scanf("%d", &ch);
            parent[ch] = i;
        }
    }
    int root, total=0; // total height
    // a bottom-up traversal
    while (1) { // queue is not empty
        int v = Q.front(); // pop Q to v
        Q.pop();
        total += h[v]; // add to total
        int p = parent[v];
        if (p == 0) { // root
            root = v;
            break;
        }
        h[p] = max(h[p],h[v]+1);
        if (--deg[p] == 0)  // push parent to queue
            Q.push(p);
    }
    // root must be the last one in the queue
    printf("%d\n%d\n",root,total);
	return 0;
}
