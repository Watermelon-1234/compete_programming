// gen the same data of p-4-12
#include <bits/stdc++.h>
using namespace std;
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}
void one(int n) {
    int i,x, y;
    printf("%d\n",n-1);
    x=ran30(1e9)+1;
    for (i=1;i<n;i++) {
        y=ran30(1e9)+1;
        printf("%d%c",y-x," \n"[i==n-1]);
        x=y;
    }
}
void two(int n, int x) {
    int i, y;
    printf("%d\n",n);
    for (i=0;i<n;i++) {
        printf("%d%c",ran30(1e7)-x," \n"[i==n-1]);
    }
}


int main() {
    int n, i, j;
	char infile[30]="P_4_13_0.in";
	srand(5817);

    for (i=1;i<3;i++) {
        infile[7]=i+'0';
        freopen(infile,"w",stdout);
        one(1e5-rand()%1000);
    }
    for (i=3;i<6;i++) {
        infile[7]=i+'0';
        freopen(infile,"w",stdout);
        two(1e5-rand()%1000, i*1000000);
    }
	return 0;
}
