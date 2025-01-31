#include<bits/stdc++.h>
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
    int i,j,k, avg=(1e9-1e8)/n;
    k=avg*n/10+ran30(avg*n/5*4);
    printf("%d %d\n",n,k);
    int p=1<<(rand()%7+7);
    for (i=0;i<n;i++) {
        j=ran30(p*avg)+1;
        printf("%d%c",j," \n"[i==n-1]);
    }
    return;
}

int main() {
	int t,i,n,ifw;
	char infile[30]="P_3_7_0.in";
	srand(5810);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
    n=200000-ran30(10000);
	one(n);
}
	return 0;
}
