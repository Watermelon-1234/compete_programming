//P-7-10  generate random matrix
#include <bits/stdc++.h>
using namespace std;
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}
#define N 510
int a[N][N];
void one(int n, int m, int r, int p) {
    //int p=1+rand()%4;
    printf("%d %d %d\n",m,n,r);
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++)
            a[i][j]=rand()%10<p;
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++)
            printf("%d%c",a[i][j]," \n"[j==n-1]);
    }

    for (int i=0 ; i<r; i++) {
        int x,y;
        do {x=ran30(m); y=ran30(n);}
        while (a[x][y]==1);
        a[x][y]=1;
        printf("%d %d%c", x+1, y+1," \n"[i==r-1]);
    }
    return;
}

int main() {
    int i,n, m, r,p;
	char infile[30]="P_7_10_0.in";
	srand(58123);
for (i=1;i<6;i++) {
    sprintf(infile+7,"%d.in",i);
	freopen(infile,"w",stdout);
	if (i<3) {
        n=i*100-rand()%100, m=i*100-rand()%100, r=100;
        p=i*3;
    } else {
        n=500-ran30(100);
        m=500-ran30(100);
        r=20000-ran30(1000);
        p=i+1;
    }
    one(n,m,r,p);
}
	return 0;
}
