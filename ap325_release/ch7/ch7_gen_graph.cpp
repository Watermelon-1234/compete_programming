//ch7  generate random digraph
#include <bits/stdc++.h>
using namespace std;
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}

void digraph(int n, int m) {
    set<pair<int,int>> S;
    printf("%d %d\n",n,m);
    while (S.size()<m) {
        int i=ran30(n), j;
        do j=ran30(n);
        while (i==j);
        S.insert({i,j});
    }
    vector<pair<int,int>> V(S.begin(),S.end());
    random_shuffle(V.begin(), V.end());
    for (auto p: V)
    printf("%d %d\n", p.first, p.second);
    return;
}


int main() {
    int i,n,m;
	char infile[30]="digraph.in";
	srand(58123);
	freopen("digraph.in","w",stdout);
    digraph(10, 20);
	return 0;
}
