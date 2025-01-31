// O(n^2) Dijkstra algorithm, dense graph using matrix
#include<bits/stdc++.h>
using namespace std;
#define N 510
#define oo 1000000000

int main() {
    int n, m, w[N][N], parent[N];
    // input data
    scanf("%d%d", &n, &m);
    if (n>510) {fprintf(stderr,"too large n\n"); return 0;}
    for (int i=0;i<n;i++) for (int j=0;j<n;j++)
        w[i][j]=oo;
    for(int i=0;i<m;i++) {
        int u,v,t;
        scanf("%d%d%d", &u, &v, &t);
        w[u][v]=w[v][u]=min(w[u][v],t);
    }
    // initial
    int d[N], source=0;
    bool done[N]={false}; // whether the distance is converged
    for (int i=0;i<n;i++) {
        d[i]=oo;
        parent[i]=-1;
    }
    d[source]=0;
    while (1) { // converge one vertex each iteration
        // find min d[] of not-done vertex
        int v=-1, mind=oo;
        for (int i=0;i<n;i++) {
            if (!done[i] && d[i]<mind) {
                v=i;
                mind=d[i];
            }
        }
        if (v<0) break; // no more reachable vertex
        done[v]=true;
        // update neighbor
        for (int i=0;i<n;i++) {
            if (d[v]+w[v][i]<d[i]) { // shorter path to i
                d[i] = d[v]+w[v][i];
                parent[i]=v;
            }
        }
    }
    int maxd=-1, cnt=0, far;
    for (int i=0;i<n;i++)
        if (d[i]<oo) {
            if (d[i]>maxd) maxd=d[i], far=i;
        } else cnt++;
    printf("%d\n%d\n",maxd,cnt);
    /*
    while (far>=0) {
        fprintf(stderr, "%d ",far);
        far=parent[far];
    }*/
    return 0;
}

