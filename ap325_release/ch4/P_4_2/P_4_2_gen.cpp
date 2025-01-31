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
    printf("%d\n",n);
    for (int i=0;i<n;i++) {
        printf("%d%c",ran30(1e5)," \n"[i==n-1]);
    }
    for (int i=0;i<n;i++) {
        printf("%d%c",ran30(1e5)," \n"[i==n-1]);
    }
    return;
}

int main() {
    int n, i, j;
	char infile[30]="P_4_2_0.in";
	srand(5817);

    for (i=1;i<4;i++) {
        infile[6]=i+'0';
        freopen(infile,"w",stdout);
        n=1e5-rand()%1000;
        one(n);
    }
    freopen("P_4_2_4.in","w",stdout);
    printf("100000\n");
    for (i=0;i<100000;i++)
        printf("%d%c",i," \n"[i==99]);
    for (i=0;i<100000;i++)
        printf("%d%c",i+1," \n"[i==99]);

    freopen("P_4_2_5.in","w",stdout);
    printf("100\n");
    for (i=0;i<100;i++)
        printf("%d%c",1000+rand()%100," \n"[i==99]);
    for (i=0;i<100;i++)
        printf("%d%c",rand()%1000," \n"[i==99]);
    return 0;

}
