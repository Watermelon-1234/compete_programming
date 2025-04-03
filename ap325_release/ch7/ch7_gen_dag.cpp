//ch7  generate random dag
#include <bits/stdc++.h>
using namespace std;
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}

void dag(int n, int m) {
    set<pair<int,int>> S;
    printf("%d %d\n",n,m);
    while (S.size()<m) {
        int i=ran30(n-1)+1, j;
        j=ran30(i);
        S.insert({i,j});
    }
    int perm[n];
    for (int i=0;i<n;i++) perm[i]=i;
    random_shuffle(perm, perm+n);
    vector<pair<int,int>> V;
    for (auto p: S) {
        V.push_back({perm[p.first],perm[p.second]});
    }
    random_shuffle(V.begin(), V.end());
    for (auto p: V)
    printf("%d %d\n", p.first, p.second);
    return;
}


int main() {
    int i,n,m;
	char infile[30]="digraph.in";
	srand(58123);
	freopen("dag.in","w",stdout);
    dag(10, 20);
	return 0;
}
