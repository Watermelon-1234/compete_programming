#include <bits/stdc++.h>
typedef long long LL;
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}
int main() {
    int i,n,m;
	char infile[30]="P_6_19_0.in";
	srand(58111);
for (i=1;i<6;i++) {
    sprintf(infile+7,"%d.in",i);
	freopen(infile,"w",stdout);
	if (i<3) n=7;
	else n=13+i;
	// n-digit number
	printf("%c",rand()%9+'1');
	for (int j=1; j<n;j++)
        printf("%c",'0'+rand()%10);
    printf("\n");
}
	return 0;
}
