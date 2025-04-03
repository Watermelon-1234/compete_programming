//P-7-6  generate random dag
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
    int perm[N], i, k=2*r;
    for (i=0;i<n;i++) perm[i]=i;
    random_shuffle(perm, perm+n);
    printf("%d %d\n",n,m);
    printf("%d %d\n",perm[0],perm[n-1]); // source, destination
    vector<EDGE> edge;
    for (i=0; i<n/10; i++) {
        edge.push_back({perm[i],perm[i+1],ran30(r)});
    }
    edge.push_back({perm[i],perm[n-1],ran30(r)});
    i++;
    for ( ; i<m; i++) {
        int u=ran30(n-1)+1, v;
        v=ran30(u);
        edge.push_back({perm[v],perm[u],ran30(k)-r});
    }
    random_shuffle(edge.begin(), edge.end());
    for (auto p: edge)
        printf("%d %d %d\n", p.u, p.v, p.w);
    return;
}
void two(int n, int m) {
    int perm[N];
    for (int i=0;i<n;i++) perm[i]=i;
    random_shuffle(perm, perm+n);
    printf("%d %d\n",n,m);
    printf("%d %d\n", perm[rand()%10], perm[n-1-rand()%10]);
    for (int i=0;i<m;i++) {
        int u=ran30(n), v;
        do v=ran30(n); while (u==v || (u%3 != v%3));
        if (u>v) swap(u,v);
        printf("%d %d %d\n", perm[u], perm[v], ran30(2000)-1000);
    }
}
int main() {
    int i,n, m, r;
	char infile[30]="P_7_6_0.in";
	srand(58123);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
	if (i==1)
        n=100, m=200, r=100;
    else {
        n=10000-ran30(1000);
        m=10000*i*2;
        r=10000;
    }
    one(n,m,r);
}
for (i=6;i<10;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
	two(10000, 100000);
}
	return 0;
}
