// distinct number -- sort
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
void one(int n, int r) {
    printf("%d\n",n);
    // not necessary distinct
    for (int i=0;i<r;i++) a[i]=ran30(P);
    for (int i=0;i<n;i++)
        printf("%d%c", a[ran30(r)], " \n"[i==n-1]);
}

int main() {
    int n, i, r;
	char infile[30]="P_2_2_0.in";
	srand(5817);

for (i=1;i<6;i++) {
    infile[6]=i+'0';
	freopen(infile,"w",stdout);
	if (i<4) n=100, r=20-rand()%5;
	else n=100000-rand()%1000, r=n/5;
	one(n,r);
}
	return 0;
}
