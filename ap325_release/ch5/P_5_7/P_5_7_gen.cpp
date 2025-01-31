#include<bits/stdc++.h>
using namespace std;
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}
#define N 100010
    int a[N];
void one(int n,int m) {
    int i;
    printf("%d\n",n);
    for (i=0;i<n-1;i++) {
        printf("%d ",1+ran30(m-1));
    }
    printf("%d\n",ran30(m));

}
void inc(int n,int m) {
    int i;
    printf("%d\n",n);
    for (i=0;i<n;i++) a[i]=ran30(m);
    sort(a, a+n);
    for (i=0;i<n;i++) {
        printf("%d%c",a[i], " \n"[i==n-1]);
    }
    return;
}
void dec(int n,int m) {
    int i;
    printf("%d\n",n);
    for (i=0;i<n;i++) a[i]=ran30(m);
    sort(a, a+n);
    for (i=n-1;i>=0;i--) {
        printf("%d%c",a[i], " \n"[i==0]);
    }
    return;
}

void dup(int n) {
    int i, h[5]={1,5,100};
    printf("%d\n",n);
    for (i=0;i<n-1;i++) {
        printf("%d ",h[rand()%3]);
    }
    printf("%d\n",h[rand()%3]);

}

int main() {
    int i,n;
	char infile[30]="P_5_7_0.in";
	srand(5810);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
	if (i==1) one(1000,1e4);
	else if (i==2) dup(200);
	else if (i==3) dec(95000+rand()%5000,1e8);
	else if (i==4) inc(95000+rand()%5000,1e8);
	else one(95000+rand()%5000,1e8);
}
    return 0;
}
