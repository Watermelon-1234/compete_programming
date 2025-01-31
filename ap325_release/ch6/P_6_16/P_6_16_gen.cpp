#include <bits/stdc++.h>
using namespace std;
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}
void one(int n, int range, int len) {
    int lenb=range/n+1;
    printf("%d\n",n);
    for (int i=0;i<n;i++) {
        int t=(len==0)? lenb:ran30(range/2)+1;
        int s=ran30(range-t-1);
        int w=(long long)n*t/range+rand()%100+1;
        if (w>100000) w=100000;
        printf("%d %d %d\n", s, s+t, w);
    }
    return;
}

int main() {
    int n, i, j;
	char infile[30]="P_6_16_0.in";
	int range[6]={0, 1000000, 100000000,100000,100000000,1000000000};
	srand(5817);

    for (i=1;i<6;i++) {
        infile[7]=i+'0';
        freopen(infile,"w",stdout);
        n=1e5-rand()%1000;
        one(n, range[i], i>2);
    }
    return 0;

}
