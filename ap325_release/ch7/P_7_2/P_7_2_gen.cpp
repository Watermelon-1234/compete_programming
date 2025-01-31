//ch7  generate random digraph
#include <bits/stdc++.h>
using namespace std;
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}

void one(int n, int m) {
    printf("%d %d\n",n,m);
    for (int i=0;i<n-1;i++)
        printf("%d ", rand()%100);
    printf("%d\n",rand()%100);
    for (int i=0; i<m; i++) {
        printf("%d %d\n", ran30(n), ran30(n));
    }
    return;
}


int main() {
    int i,n;
	char infile[30]="P_7_2_0.in";
	srand(5810);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
	one(50000-ran30(10000), (1<<(2*i-1))*500);
}
	return 0;
}
