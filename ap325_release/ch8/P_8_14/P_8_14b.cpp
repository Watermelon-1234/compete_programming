// unweighted tree diameter, farthest of farthest algorithm
// using bfs
#include <bits/stdc++.h>
using namespace std;
#define N 100010
vector<int> adj[N]; // adjacency list
int n, d[N];
// find all distances d[v] from r
void bfs(int r) {
    for (int i=0; i<n; i++) d[i]=-1; // unvisited
    queue<int> Q;
    Q.push(r);
    d[r] = 0;
    while (!Q.empty()) {
        int v=Q.front();
        Q.pop();
        for (int u: adj[v]) {
            if (d[u] >= 0) continue; // visited
            d[u] = d[v] + 1;
            Q.push(u);
        }
    }
	return;
}

int main() {
	scanf("%d",&n);
	for (int i=0; i<n-1; i++) {
        int j,k;
        scanf("%d%d", &j, &k);
        adj[j].push_back(k);
        adj[k].push_back(j);
	}
	bfs(rand()%n); // random root
	int farthest = max_element(d, d+n) - d;
    bfs(farthest);
	printf("%d\n", *max_element(d, d+n));
	return 0;
}
