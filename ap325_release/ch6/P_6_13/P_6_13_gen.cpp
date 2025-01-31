#include <cstdio>
#include <algorithm>
#include <vector>
#include<assert.h>
using namespace std;
#define R 1000
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}

void one(int n, int m) {
    int i,j,s,q;
    printf("%d %d\n",n,m);
    for (i=0;i<n-1;i++) {
        printf("%d ",ran30(R)+1);
    }
    printf("%d\n",ran30(R)+1);
}

int main() {
    int i,n;
	char infile[30]="P_6_13_0.in";
	srand(58);
for (i=1;i<6;i++) {
    sprintf(infile+7,"%d.in",i);
	freopen(infile,"w",stdout);
	if (i<3) one(10000, rand()%100+1);
	else
        one(200000-i*100, 10<<(i*2));
}
	return 0;
}
