// generate a random walk from 1 to p, each step +s or -t
#include <stdio.h>
#include <stdlib.h>
#define N 60
int a[N][N];

void one(int m,int n) {
    int i,j;
    printf("%d %d\n",m,n);
    for (i=0; i<m; i++) {
        for (j=0;j<n-1; j++)
            printf("%d ",rand()&1);
        printf("%d\n",rand()&1);
    }
    return;
}

int main() {
    int i,n,m;
	char infile[30]="P_6_21_0.in";
	srand(58111);
for (i=1;i<6;i++) {
    sprintf(infile+7,"%d.in",i);
	freopen(infile,"w",stdout);
        m=25-rand()%5;
        n=25-rand()%5;
	one(m,n);
}
	return 0;
}
