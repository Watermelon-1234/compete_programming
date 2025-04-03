#include<bits/stdc++.h>
using namespace std;
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}
typedef long long LL;
// find x^y mod P
LL exp(LL x, LL y, LL p) {
    if (y==0) return 1;
    if (y & 1) return (exp(x, y-1,p)*x)%p;
    // otherwise y is even
    LL t=exp(x, y/2, p);
    return (t*t)%p;
}
int main() {
	int t,i,n;
	char infile[30]="P_2_9_0.in";
	srand(5817);
    int pr[6]={11, 10007, 100019, 1000000009, 1000000007, 1000000009};
for (i=1;i<4;i++) {
    infile[6]=i+'0';
	freopen(infile,"w",stdout);
	n=12+i*8;
	int p=pr[i];
	printf("%d %d\n",n, p);
	for (t=0;t<n;t++) {
        printf("%d%c", ran30(p-1)+1, " \n"[t==n-1]);
	}
}
// large solution
for (;i<6;i++) {
    infile[6]=i+'0';
	freopen(infile,"w",stdout);
	n=36;
	int p=pr[i];
	int a[50];
	for (t=0;t<10+i;t++) a[t]=1;
    int x=ran30(p-1)+1;
    int y=exp(x,p-2,p);
    for ( ;t<25+i;t++) a[t]=x;
    for ( ; t<30+i;t++) a[t]=y;
    for ( ; t<n;t++) a[t]=ran30(p-1)+1;
    random_shuffle(a, a+n);
	printf("%d %d\n",n, p);
	for (t=0;t<n;t++) {
        printf("%d%c", a[t], " \n"[t==n-1]);
	}
}
	return 0;
}
