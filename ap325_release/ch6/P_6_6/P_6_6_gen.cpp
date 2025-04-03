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

void one(int m, int n) {
    int i,j,s,q=R-rand()%100;
    int t=R+q;
    printf("%d %d\n",m, n);
    for (i=0;i<m;i++) {
        for (j=0;j<n;j++)
            printf("%d%c",ran30(t)-q, " \n"[j==n-1]);
    }
}

int main() {
    int i,n,m;
	char infile[30]="P_6_6_0.in";
	srand(58111);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
	one(200-rand()%20, 200-rand()%20);
}
	return 0;
}
