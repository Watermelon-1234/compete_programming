// generate a 0/1 matrix
#include<bits/stdc++.h>
using namespace std;
#define N 510

int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}

void one(int m,int n, int p) {
    char str[N][N];
    int i,j,k;
    printf("%d %d\n",m,n);
    for (i=0; i<m;i++) {
        for (j=0;j<n;j++)
            str[i][j]=(rand()%100<p)?'1':'0';
        str[i][n]='\0';
    }
    for (i=0;i<3;i++) for (j=0;j<3;j++)
        str[i][j]='0', str[m-1-i][n-1-j]='0';
    for (i=0;i<m;i++)
        printf("%s\n", str[i]);
    return;
}
void spe(int m, int n) {
    char str[N][N];
    int i,j,k;
    printf("%d %d\n",m,n);
    for (i=0;i<m;i++) {
        for (j=0;j<n;j++)
            str[i][j]='1';
        str[i][n]='\0';
    }
    for (i=0; i<m;i+=2)
        for (j=0;j<n;j++)
            str[i][j]='0';
    k=-1;int r;
    for (i=1; i<m; i+=2) {
        str[i][r=rand()%n] ='0';
        if (r==k) fprintf(stderr,"X\n");
        k=r;
    }
    str[m-1][n-1]='0';
    for (i=0;i<m;i++)
        printf("%s\n", str[i]);
    return;
}
int main() {
    int i,n, m;
	char infile[30]="P_7_4_0.in";
	srand(5810);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
	if (i==1) one(20,20, 25);
	else if (i<4) {
        m=500-rand()%50;
        n=500- rand()%50;
        one(m,n, i*9);
	} else spe(499,499);
}
	return 0;
}
