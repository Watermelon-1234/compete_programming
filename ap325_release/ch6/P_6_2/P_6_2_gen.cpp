#include <cstdio>
#include <algorithm>
#include <vector>
#include<assert.h>
using namespace std;
#define R 10000
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}

void one(int n) {
    int i,j,s,q;
    printf("%d\n",n);
    for (i=0;i<n-1;i++) {
        printf("%d ",ran30(R));
    }
    printf("%d\n",ran30(R));
}

int main() {
    int i,n;
	char infile[30]="P_6_2_0.in";
	srand(58);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
	if (i<3) one(1000);
	else
        one(100000-i*100);
}
	return 0;
}
