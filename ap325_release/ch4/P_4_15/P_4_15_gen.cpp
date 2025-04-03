#include <bits/stdc++.h>
using namespace std;
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}

void one(int n,int d) {
    int i, p=d/2;
    printf("%d\n",n);
    for (i=0;i<n;i++) {
        printf("%d %d\n",ran30(d)-p,ran30(d)-p);
    }
}


int main() {
    int n, i, j;
	char infile[30]="P_4_15_0.in";
	srand(5817);
    for (i=1;i<6;i++) {
        infile[7]='0'+i;
        freopen(infile,"w",stdout);
        if (i<3) one(1000,20000);
        else one(1e5-rand()%1000, 2e8);
    }
    return 0;
}
