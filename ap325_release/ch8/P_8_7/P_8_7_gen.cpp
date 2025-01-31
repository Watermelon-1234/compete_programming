// tree format
// n
// c[0] c[1] ...
// p[v] v
// root =0
#include<cstdio>
#include<cstdlib>
#include <algorithm>
#include <string.h>
#define N 200010
using namespace std;
int lab[N],p[N],c[N];

int ran30(int R) {
    #if RAND_MAX<40000
    return ((rand()<<15)|rand())%R;
    #else
    return rand()%R;
    #endif
}

void perm(int n) {
    for (int i=0;i<n;i++) lab[i]=i;
    //return;
    random_shuffle(lab+1,lab+n);
    return;
}
void output(int n) {
    int i;
	printf("%d\n",n);
	for (i=0;i<n-1;i++) printf("%d ",c[i]);
	printf("%d\n",c[i]);
	for (i=1;i<n;i++)
        printf("%d %d\n",p[i],i);
    return;
}
// random tree with random color
void rndtree(int n, int mc, int cf) {
	int i,j,up,x;
	perm(n);
	p[lab[0]]=-1;
	for (i=1;i<n;i++) {
        j=ran30(i);
        p[lab[i]]=lab[j];
	}
	for (i=0;i<n;i++) {
        j=ran30(mc);
        c[lab[i]]= j- j%cf;
	}
    output(n);
}
// a random tree with a path length =f
void longpath(int n,int f, int mc, int cf) {
	int i,j;
	perm(n);
	p[lab[0]]=-1;
	for (i=1;i<f;i++) p[lab[i]]=lab[i-1];
	for (;i<n;i++) {
        j=f/2+ran30(i-f/2);
        p[lab[i]]=lab[j];
	}
	for (i=0;i<n;i++) {
        j=ran30(mc);
        c[lab[i]]= j- j%cf;
	}
    output(n);
}

// tree with many paths of length f
void ptree(int n,int f, int mc, int cf) {
	int i,j,up,mm,v;
	perm(n);
	p[lab[0]]=-1;
	for (i=1;i<f;i++) {
        p[lab[i]]=lab[i-1];
	}
	for (;i<n-f;i+=f) {
        v=ran30(i);
        p[lab[i]]=lab[v];
        for (j=1;j<f;j++) {
            p[lab[i+j]]=lab[i+j-1];
        }
	}
	for (;i<n;i++) {
        p[lab[i]]=lab[ran30(i)];
	}
	for (i=0;i<n;i++) {
        j=ran30(mc);
        c[lab[i]]= j- j%cf;
	}
    output(n);
}

int main() {
	int i,j,cf;
	int n[5]={0,1000,100000,100000,200000};
	int col[5]={0,1,10,10000,1000000000};
	int cfl[6]={17,107,10007,100007,1000007,10000007};
	char infile[30]="P_8_7_0.in";
	srand(58123);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
    if (i<=2) cf=1;
    else if (i<=4) cf=cfl[1];
    else cf=cfl[3+i%3];

    if (i<=2) rndtree(n[i],col[i],cf);
    else if (i==3) longpath(n[i],n[i]*2/10,col[i],cf);
    else if (i==4) longpath(n[4],n[i]/2, col[3],cf);
    else ptree(n[4],n[4]/20,col[4],cf);
}
return 0;

}
