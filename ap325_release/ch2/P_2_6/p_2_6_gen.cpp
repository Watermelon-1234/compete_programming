#include <bits/stdc++.h>
using namespace std;
#define N 100000
#define P 1000000000
int a[N+10];
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}
void one(int m, int n, int k) {
    printf("%d %d %d\n", m,n,k);
    set<int> S;
    int p2=P/2;
    for (int i=0;i<m;i++) {
        int t;
        do {
            t=ran30(P)-p2;}
        while (S.find(t)!=S.end());
        S.insert(t);
        printf("%d%c",t," \n"[i==m-1]);
    }
    S.clear();
    for (int i=0;i<n;i++) {
        int t;
        do {
            t=ran30(P)-p2;}
        while (S.find(t)!=S.end());
        S.insert(t);
        printf("%d%c",t," \n"[i==n-1]);
    }
}

int main() {
    int m, n, k,i;
	char infile[30]="P_2_6_0.in";
	srand(5817);

for (i=1;i<6;i++) {
    infile[6]=i+'0';
	freopen(infile,"w",stdout);
	m=N-rand()%10000;
	n=N-rand()%10000;
	k=rand()%10000000 - 5000000;
	one(m,n,k);
}
	return 0;
}
