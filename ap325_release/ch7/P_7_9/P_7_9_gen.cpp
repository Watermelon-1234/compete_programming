//P-7-6  generate random graph
#include <bits/stdc++.h>
using namespace std;
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}
#define N 10010
struct EDGE {
    int u,v,w;
};
void one(int n, int m, int r) {
    int perm[N], i;
    for (i=0;i<n;i++) perm[i]=i;
    random_shuffle(perm+1, perm+n);
    printf("%d %d\n",n,m);
    vector<EDGE> edge;
    for (i=0; i<n/10; i++) {
        edge.push_back({perm[i],perm[i+1],ran30(100)});
    }
    for ( ; i<m; i++) {
        int u=ran30(n-1)+1, v;
        v=ran30(u);
        edge.push_back({perm[v],perm[u],ran30(r)});
    }
    random_shuffle(edge.begin(), edge.end());
    for (auto p: edge)
        printf("%d %d %d\n", p.u, p.v, p.w);
    return;
}

int main() {
    int i,n, m, r;
	char infile[30]="P_7_9_0.in";
	srand(58123);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
	if (i<3)
        n=100+i*200, m=500, r=100;
    else {
        n=10000-ran30(1000);
        m=10000*i*2;
        r=10000;
    }
    one(n,m,r);
}
	return 0;
}
