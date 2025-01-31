// P_3_6b, topological sort and linked list
#include <queue>
#include <cstdio>
using namespace std;
#define N 100010
#define oo 1000000001
struct {
    int c, h; // center and height
    int pre, next; // linked list
    int alive;
} tree[N];
queue<int> Q; // queue for removed tree
// check if i is removable, if yes, remove it
void removable(int i) {
    if (!tree[i].alive) return;
    int s=tree[i].pre, t=tree[i].next;
    if (tree[i].c - tree[i].h >= tree[s].c \
        || tree[i].c+tree[i].h<=tree[t].c) {
        tree[i].alive = 0;
        Q.push(i); // insert into queue
        tree[s].next = t; //remove from linked list
        tree[t].pre =s;
    }
    return;
}

int main() {
    int n,l,i;
    int total=0, high=0;
    scanf("%d%d",&n,&l);
    // initial data
    for (i=1; i<=n; i++)
        scanf("%d", &tree[i].c);
    for (i=1; i<=n; i++)
        scanf("%d", &tree[i].h);
    for (i=1; i<=n; i++) {
        tree[i].pre = i-1;
        tree[i].next = i+1;
        tree[i].alive = 1;
    }
    // two boundaries
    tree[0].c = 0, tree[0].h = oo;
    tree[n+1].c = l, tree[n+1].h = oo;
    // initial check
    for (i=1; i<=n; i++)
        removable(i);
    while (!Q.empty()) {
        int v=Q.front();
        Q.pop();
        total++;
        high = max(high, tree[v].h);
        // check its previous and next
        removable(tree[v].pre);
        removable(tree[v].next);
    }
    printf("%d\n%d\n", total,high);
    return 0;
}
