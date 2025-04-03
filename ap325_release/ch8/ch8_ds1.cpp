// tree, data structure demo, parent and child
#include <bits/stdc++.h>
using namespace std;
#define N 1000
int parent[N];
vector<int> child[N]; // list of children

// parent to child
void p2c(int n) {
    for (int i=0; i<n; i++)
        child[i].clear();
    for (int i=0; i<n; i++) // set i as a child of parent[i]
        child[parent[i]].push_back(i);
    return;
}
// child to parent, parent[root] = -1, return root
int c2p(int n) {
    for (int i=0; i<n; i++)
        parent[i] = -1;  // -1 as no parent
    for (int i=0; i<n; i++) {
        for (int c: child[i]) // each child of i
            parent[c] = i;
    }
    for (int i=0; i<n; i++) // find root
        if (parent[i]==-1)
            return i;
}
