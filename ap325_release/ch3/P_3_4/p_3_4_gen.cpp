#include <bits/stdc++.h>

#define R 10000000
#define R2 1000000
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}
void one(int n) {
    int i,j,k;
    printf("%d\n",n);
    j=10000;
    for (i=0;i<j;i++) printf("%d ",ran30(R)+1);
    for (;i<j+80000;i++)
        printf("%d ",R/2+(i+rand()%2)*10);
    for ( ; i<j+160000;i++)
        printf("%d ",R-1000000-i*10);
    for (; i<n-1; i++) printf("%d ",ran30(R/2)+1);
    printf("%d\n",ran30(R)+1);
    return;
}

int main() {
	int t,i,n,ifw;
	char infile[30]="P_3_4_0.in";
	srand(5810);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
    n=200000-ran30(10000);
	one(n);
}
	return 0;
}
