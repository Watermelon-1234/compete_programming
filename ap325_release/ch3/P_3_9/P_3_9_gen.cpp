#include<bits/stdc++.h>
#define N 200010
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}
void one(int n, int l, int k) {
    int i;
    printf("%d %d\n",n,l);
    for (i=0;i<n;i++) {
        printf("%d%c",ran30(k)," \n"[i==n-1]);
    }
    return;
}

int main() {
	int t,i,n,l;
	char infile[30]="P_3_9_0.in";
	srand(5810);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
    n=200000-ran30(10000);
    t=(1<<(3*i))+rand()%100;
	one(n,n/100+ran30(n/3),t);
}
	return 0;
}
