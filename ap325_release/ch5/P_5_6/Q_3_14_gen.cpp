// random abc
// ax+by=c
// more |a/b|, smaller c
#include<bits/stdc++.h>
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}

void ran(int n,int m) {
    int i,t,a,b,p;
    printf("%d %d\n",n,m);
    if (n==0) return;
    for (i=0;i<n;i++) {
        printf("%d %d\n",ran30(10000),ran30(10000));
    }
    for (i=0;i<m-1;i++) {
        printf("%d ",ran30(200000)-100000);
    }
    printf("%d\n",0);

}
void rr(int n,int m,int f) {
    int i,t,a,b,p;
    printf("%d %d\n",n,m);
    if (n==0) return;
    for (i=0;i<n;i++) {
        a=100+i;
        b=-(a/10)*(a/10);
        if (f) b+=rand()%(a/f);
        if (i&1) a=-a;
        //if (b==0) b=1;
        printf("%d %d\n",a,b);
    }
    p=(2*n+200)/m;
    for (i=0;i<m-1;i++) {
        t=10+p*i;//rand();
        if (rand()&1) t=-t;
        printf("%d ",t);
    }
    printf("%d\n",0);

}
main() {
    int i,n;
	char infile[30]="Q_3_14_0.in";
	srand(5810);
for (i=1;i<6;i++) {
    sprintf(infile+7,"%d.in",i);
	freopen(infile,"w",stdout);
	if (i<3) ran(10000,1000);
	else if (i==3) ran(95000+rand()%5000,50000);
	else if (i==4) rr(90000+rand()%5000,50000,8);
	else rr(90000,50000,10);
}
    return 0;
}
