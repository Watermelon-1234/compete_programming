// P-7-1, using adjacency list
#include <bits/stdc++.h>
using namespace std;
#define N 102
int n, m, s;
vector<int> adj[N];
int d[N]; // distance

void bfs(int s) {
    bool visit[N] = {false};
    queue<int> Q;
    Q.push(s);
    visit[s]=true, d[s]=0;
    int cnt=0, totald=0;
    while (!Q.empty()) {
        int v=Q.front();
        Q.pop();
        for (int u: adj[v]) {
            if (!visit[u]) {
                d[u] = d[v]+1;
                visit[u] = true;
                Q.push(u);
                cnt++; // num of reachable
                totald += d[u]; // total distance
            }
        }
    }
    printf("%d\n%d\n", cnt, totald);
    return;
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    for (int i=0; i<m; i++) {
        int from, to;
        scanf("%d%d", &from, &to);
        adj[from].push_back(to);
    }
    bfs(s);
    return 0;
}
