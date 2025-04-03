// generate a matrix without repeats
#include<bits/stdc++.h>
using namespace std;
#define N 101
#define M 100000
int id[100005];

int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}

void one(int m,int n) {
    int i,j,k;
    random_shuffle(id, id+M);
    printf("%d %d\n",m,n);
    k=0;
    for (i=0;i< m;i++) {
        for (j=0;j<n-1;j++)
            printf("%d ",id[k++]);
        printf("%d\n",id[k++]);
    }
    return;
}

int main() {
    int i,n, m;
	char infile[30]="P_7_3_0.in";
	srand(5810);
	for (i=0;i<100000;i++) id[i]=i;
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
	m=100-rand()%20;
    n= 100- rand()%20;
	one(m,n);
}
	return 0;
}
