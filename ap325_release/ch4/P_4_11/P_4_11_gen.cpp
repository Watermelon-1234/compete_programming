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
    int i,j,s,t;
    printf("%d\n",n);
    for (i=0;i<1000;i++) {
        s=ran30(50000);t=49500000+ran30(500000);
        printf("%d %d\n",s,t);
    }
    for (;i<1500;i++) {
        s=50000000+ran30(48000000);
        t=ran30(10000);
        printf("%d %d\n",s,s+t);
    }
    for (;i<n/2;i++) {
        s=50000000+ran30(48000000);
        t=ran30(2000);
        printf("%d %d\n",s,s+t);
    }
    for (;i<n;i++) {
        s=50000000+ran30(48000000);
        t=ran30(500);
        printf("%d %d\n",s,s+t);
    }
}

int main() {
    int n, i, j;
	char infile[30]="P_4_11_0.in";
	srand(5817);

    for (i=1;i<6;i++) {
        infile[7]=i+'0';
        freopen(infile,"w",stdout);
        one(1e5-ran30(10000));
    }
	return 0;
}
