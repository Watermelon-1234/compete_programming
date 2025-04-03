#include <cstdio>
#include <algorithm>
#include <vector>
#include<assert.h>
using namespace std;
#define R 1000000
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}
int ar[100010];

void one(int n) {
    int i,j,s,q;
    printf("%d\n",n);
    for (i=0;i<n-1;i++) {
        printf("%d ",ran30(R));
    }
    printf("%d\n",ran30(R));
}

void srt(int n) {
    int i,j,s,q;
    printf("%d\n",n);
    for (i=0;i<n;i++) ar[i]=ran30(R);
    int m=n/2;
    sort(ar,ar+m);
    sort(ar+m,ar+n);
    for (i=0;i<n-1;i++) {
        printf("%d ",ar[i]);
    }
    printf("%d\n",ar[i]);
}

void srt2(int n) {
    int i,j,s,q;
    printf("%d\n",n);
    for (i=0;i<n;i++) ar[i]=ran30(R);
    sort(ar,ar+n);
    for (s=0;s<100;s++) {
        i=ran30(n);
        j=ran30(n);
        q=ar[i]; ar[i]=ar[j]; ar[j]=q;
    }
    for (i=n-1;i>0;i--) {
        printf("%d ",ar[i]);
    }
    printf("%d\n",ar[i]);
}

int main() {
    int i,n;
	char infile[30]="P_5_4_0.in";
	srand(5810);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
	if (i==1) one(1000);
	else if (i<4)
        srt2(100000-i*100);
    else
        one(100000-i*100);
}
	return 0;
}
