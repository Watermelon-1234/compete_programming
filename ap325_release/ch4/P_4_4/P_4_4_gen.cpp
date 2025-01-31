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
        int t=(len==0)? lenb:ran30(lenb)+1+rand()%5;
        int s=ran30(range-lenb);
        printf("%d %d\n",s, s+t);
    }
    return;
}

int main() {
    int n, i, j;
	char infile[30]="P_4_4_0.in";
	int range[6]={0, 1000000, 100000000,100000,100000000,1000000000};
	srand(5817);

    for (i=1;i<6;i++) {
        infile[6]=i+'0';
        freopen(infile,"w",stdout);
        n=1e5-rand()%1000;
        one(n, range[i], i>2);
    }
    return 0;

}
