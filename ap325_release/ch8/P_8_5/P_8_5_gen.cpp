#include <bits/stdc++.h>
using namespace std;
#define N 1000010

int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}

int lab[N], lc[N], rc[N];
int deg[N];

void perm(int n) {
    for (int i=0;i<2*n-1;i++) lab[i]=i+1;
    //return;
    random_shuffle(lab+1,lab+n-1);
    return;
}

// a binary tree with a path length =f
// only internal node
// internal node = 1~n-1
void tree(int n,int f) {
	int i,j;
	perm(n);
	for (i=0;i<f-1;i++) deg[i]=1;
	for ( ;i<n-1;i++) deg[i]=0;
	for (i=1;i<f;i++) lc[i-1] = i;
	for (;i<n-1;i++) {
        do j=ran30(i);
        while (deg[j]==2);
        if (deg[j]==0) lc[j]=i;
        else rc[j]=i;
        deg[j]++;
	}
	j=n-1;
	for (i=0;i<n-1;i++) {
        if (deg[i]==0) {
            lc[i]=j++;
            rc[i]=j++;
        }
        else if (deg[i]==1)
            rc[i]=j++;
	}
    for (i=0;i<n-1;i++)
        printf("%d %d %d\n",lab[i],lab[lc[i]],lab[rc[i]]);
}
void bal(int n) {
    int i;
    for (i=1;i<n;i++) {
        printf("%d %d %d\n",i,2*i,2*i+1);
    }
}
void one(int n, int m, int ini, int type) {
    int i,j;
    printf("%d %d\n",n,m);
    if (ini==0)
        for (i=0;i<n;i++) printf("0%c"," \n"[i==n-1]);
    else {
        for (i=0;i<n;i++) printf("%d%c",rand()%ini," \n"[i==n-1]);
    }
    for (i=0;i<m;i++) printf("%d%c",rand()%20000+1," \n"[i==m-1]);
    // tree
    if (type==0) bal(n);
    else if (type==1) bal(n);
    else tree(n,type);
    return;
}

int main() {
    int i,n, m, r,L;
	char infile[30]="P_8_5_0.in";
	srand(58135);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
	if (i<3) {
        n=1000-rand()%100;
        L=100-rand()%10;
        one(n,L,100,1);
    } else {
        n=100000-rand()%1000;
        L=100-rand()%10;
        one(n,L,10,20000+rand()%5000);
    }
}
	return 0;
}
