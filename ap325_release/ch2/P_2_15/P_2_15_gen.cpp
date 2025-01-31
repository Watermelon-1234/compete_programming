#include<bits/stdc++.h>
using namespace std;
void one(int n, int m) {
    int i,j,k=0, total=0;
    printf("%d %d\n",n,m);
    for (i=0;i<n;i++) {
        k=rand()%10000+1;
        printf("%d%c",k," \n"[i==n-1]);
        total+=k;
    }
    k = total/5;
    total = total - k - 10;
    for (i=0;i< m;i++)
        printf("%d%c",k+rand()%total," \n"[i==m-1]);
    return;
}
void two(int n, int m) {
    int i,j,k=0, total=0;
    printf("%d %d\n",n,m);
    int seg=10000;
    i=0;
    while (i<n-2*seg-10) {
        for (j=0;j<seg;j++) {
            k=rand()%100+1;
            printf("%d ",k);
            total+=k;
        }
        for (j=0;j<seg;j++) {
            k=9900+rand()%100;
            printf("%d ",k);
            total+=k;
        }
        i+=seg*2;
    }
    for ( ;i<n;i++) {
        k=rand()%10000+1;
        printf("%d%c",k," \n"[i==n-1]);
        total+=k;
    }
    k = total/5;
    total = total - k - 10;
    for (i=0;i< m;i++)
        printf("%d%c",k+rand()%total," \n"[i==m-1]);
    return;
}
void three(int n, int m) {
    int i,j,k=0, total=0;
    printf("%d %d\n",n,m);
    for (i=0;i<9*n/10;i++) {
        k=rand()%100+1;
        printf("%d ",k);
        total+=k;
    }
    for (;i<n-100;i++) {
        k=4500+rand()%100;
        printf("%d ",k);
        total+=k;
    }
    for ( ;i<n;i++) {
        k=rand()%16000000+1;
        printf("%d%c",k," \n"[i==n-1]);
        total+=k;
    }
    for (i=0; i<m/2; i++)
        printf("%d ",total/2-rand()%100);
    k = total/5;
    total = total - k - 10;
    for ( ;i< m;i++)
        printf("%d%c",k+rand()%total," \n"[i==m-1]);
    return;
}
int main() {
    int n, i, j;
	char infile[30]="P_2_15_0.in";
	srand(5810);
    for (i=1;i<6;i++) {
        infile[7]='0'+i;
        freopen(infile,"w",stdout);
        if (i<3) two(200000-i*100, 20000-rand()%100);
        else three(200000-i*100, 20000-rand()%100);
    }
	return 0;
}

