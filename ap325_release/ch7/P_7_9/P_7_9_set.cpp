//Dijkstra algorithm using map
#include<bits/stdc++.h>
using namespace std;
#define N 10010
#define oo 1000000001

vector<pair<int,int> > adj[N]; //Adjacency list
int d[N], parent[N];
bool done[N]={false};

int main() {
    int n, m;
    // input data
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;i++) {
        int u,v,t;
        scanf("%d%d%d", &u, &v, &t);
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }
    // initial
    int source=0;
    for (int i=0;i<n;i++) d[i]=oo;
    for (int i=0;i<n;i++) parent[i]=-1;
    set<pair<int,int>> PQ; // (d[], vertex) as a priority queue
    PQ.insert({d[source]=0,source});
    while (!PQ.empty()) { // converge one vertex each iteration
        auto p=*PQ.begin(); // find min d[] of not-done vertex
        PQ.erase(PQ.begin());
        int v=p.second;
        if (done[v]) fprintf(stderr,"something wrong");
        done[v]=true;
        // update neighbor
        for (auto e: adj[v]) {
            int u=e.first, w=e.second;
            //if (done[u]) continue;
            if (d[v]+w < d[u]) {
                PQ.erase({d[u],u});
                PQ.insert({d[u]=d[v]+w, u});
                parent[u]=v;
            }
        }
    }
    int maxd=-1, cnt=0, far, leng=0;
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

