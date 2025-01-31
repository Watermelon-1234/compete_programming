#include <bits/stdc++.h>
using namespace std;
#define R 100
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}

void one(int n) {
    int m=1<<n;
    printf("%d\n",n);
    for (int i=0; i<m; i++)
        printf("%d%c",rand()%100," \n"[i==m-1]);
    return;
}

int main() {
    int i,n,m;
	char infile[30]="P_6_20_0.in";
	srand(58111);
for (i=1;i<6;i++) {
    sprintf(infile+7,"%d.in",i);
	freopen(infile,"w",stdout);
	n=14+i;
	one(n);
}
	return 0;
}
