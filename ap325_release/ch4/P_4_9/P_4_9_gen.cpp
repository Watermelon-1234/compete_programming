#include <bits/stdc++.h>
using namespace std;
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}
void rs(int n, int R, int k) {
    int i;
    printf("%d %d\n",n,k);
    for (i=1;i<n;i++) printf("%d ",ran30(R));
    printf("%d\n",ran30(R));
}


int main() {
    int n, i, j;
	char infile[30]="P_4_9_0.in";
	srand(5817);

    for (i=1;i<6;i++) {
        infile[6]=i+'0';
        freopen(infile,"w",stdout);
        if (i<3) rs(500,1000000000,1+rand()%30);
        else {
            n=48000+rand()%2000;
            rs(n,1000000000,1+rand()%(n/3));
        }
    }
	return 0;
}
