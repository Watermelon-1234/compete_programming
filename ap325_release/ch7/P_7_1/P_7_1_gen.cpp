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
    printf("%d %d\n%d\n",n,m,rand()%n);
    for (int i=0; i<m; i++) {
        printf("%d %d\n", ran30(n), ran30(n));
    }
    return;
}


int main() {
    int i,n;
	char infile[30]="P_7_1_0.in";
	srand(5810);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
	one(100-rand()%20, (1<<i)*50);
}
	return 0;
}
