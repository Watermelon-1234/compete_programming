#include <bits/stdc++.h>
using namespace std;
#define R 100000
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}

void one(int n) {
    printf("%d\n",n);
    return;
}

int main() {
    int i,n,m;
	char infile[30]="P_6_11_0.in";
	srand(58111);
for (i=1;i<6;i++) {
    sprintf(infile+7,"%d.in",i);
	freopen(infile,"w",stdout);
	one(100-rand()%100);
}
	return 0;
}
