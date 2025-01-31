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
void one(int n, int l) {
    int i,j,k, r=(1e9-1e8);
    printf("%d %d\n",n,l);
    for (i=0;i<n;i++) {
        printf("%d%c",ran30(r)," \n"[i==n-1]);
    }
    return;
}

int main() {
	int t,i,n,l;
	char infile[30]="P_3_8_0.in";
	srand(5810);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
    n=200000-ran30(10000);
    l=(1<<(2*i+7))-rand()%100;
	one(n,l);
}
	return 0;
}
