// P-7-1, using matrix
#include <bits/stdc++.h>
using namespace std;
#define N 102
int n, m, s;
int adj[N][N]={0};
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
        for (int i=0;i<n;i++) {
            if (adj[v][i] && !visit[i]) {
                d[i]=d[v]+1;
                visit[i]=true;
                Q.push(i);
                cnt++; // num of reachable
                totald+=d[i]; // total distance
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
        adj[from][to]=1;
    }
    bfs(s);
    return 0;
}
