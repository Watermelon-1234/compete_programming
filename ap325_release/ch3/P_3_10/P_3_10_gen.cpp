#include<bits/stdc++.h>
using namespace std;
#define N 200010
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}
void one(int n,int r) {
    int i;
    printf("%d\n",n);
    for (i=0;i<n-1;i++) {
        printf("%d ",ran30(r));
    }
    printf("%d\n",ran30(r));
    return;
}
// n number range [0,r), at most t different
void two(int n,int r, int t) {
    int i;
    set<int> S;
    while (S.size()<t) {
        S.insert(ran30(r));
    }
    vector<int> ar(S.begin(),S.end());
    printf("%d\n",n);
    for (i=0;i<n;i++) {
        printf("%d%c",ar[ran30(t)]," \n"[i==n-1]);
    }
    return;
}

int main() {
	int t,i,n,l;
	char infile[30]="P_3_10_0.in";
	srand(5810);
for (i=1;i<6;i++) {
    sprintf(infile+7,"%d.in",i);
	freopen(infile,"w",stdout);
    n=200000-ran30(10000);
    if (i==1) two(n,1000,1000);
    else if (i==2) two(n,10000,10000);
    else two(n,1e9,i<4? 5000: i<5? 10000:50000);
}
	return 0;
}
