#include <bits/stdc++.h>
using namespace std;
#define R 100000
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}

void one(int n) {
    int i,j, t=3*R/n;
    int r=rand()%5+1;
    pair<int,int> p[200];
    for (i=0;i<n-10;i++)
        p[i].first=ran30(t)+1;
    for ( ;i<n;i++)
        p[i].first=rand()%10+1;
    for (i=0;i<n-10;i++)
        p[i].second=p[i].first*r+rand()%100;
    for (; i<n;i++)
        p[i].second=rand()%10+1;
    random_shuffle(p, p+n);
    printf("%d %d\n",n, R-rand()%3000);
    for (i=0;i<n; i++)
        printf("%d%c",p[i].first, " \n"[i==n-1]);
    for (i=0;i<n; i++)
        printf("%d%c",p[i].second, " \n"[i==n-1]);
    return;
}

int main() {
    int i,n,m;
	char infile[30]="P_6_9_0.in";
	srand(58111);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
	one(100-i);
}
	return 0;
}
