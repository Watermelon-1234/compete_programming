#include <bits/stdc++.h>
using namespace std;
#define R 100000
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}

void one(int n, int L) {
    printf("%d %d\n",n, L);
    set<int> V;
    while (V.size()<n) {
        int t=ran30(L-5)+1;
        V.insert(t);
    }
    int i=0;
    for (auto it=V.begin(); it!=V.end(); it++, i++)
        printf("%d%c",*it," \n"[i==n-1]);
    return;
}
void spe(int n, int L) {
    printf("%d %d\n",n, L);
    set<int> V;
    while (V.size()<2*n) {
        int t=ran30(L-5)+1;
        V.insert(t);
    }
    // delete range
    while (V.size()>n) {
        int t=ran30(L);
        auto it=V.lower_bound(t);
        int cnt=10;
        while (it!=V.end() && cnt>0 && V.size()>n) {
            it=V.erase(it);
            cnt--;
        }
    }
    int i=0;
    assert(V.size()==n);
    for (auto it=V.begin(); it!=V.end(); it++, i++)
        printf("%d%c",*it," \n"[i==n-1]);
    return;
}

int main() {
    int i,n,m;
	char infile[30]="P_6_17_0.in";
	srand(58111);
for (i=1;i<6;i++) {
    sprintf(infile+7,"%d.in",i);
	freopen(infile,"w",stdout);
	n=200-rand()%20, m=1000000-ran30(1e5);
	if (i<4) one(n,m);
	else spe(n,m);
}
	return 0;
}
