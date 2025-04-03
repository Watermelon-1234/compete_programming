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
    printf("%d\n",n);
    for (int i=0;i<n;i++)
        printf("%d%c",ran30(1e8)," \n"[i==n-1]);
    return;
}
void inc(int n) {
    printf("%d\n",n);
    vector<int> V;
    for (int i=0;i<n;i++)
        V.push_back(ran30(1e8));
    sort(V.begin(), V.end());
    for (int i=0;i<n/10;i++) {
        int j=ran30(n), k=ran30(n);
        swap(V[j], V[k]);
    }
    for (int i=0;i<n;i++)
        printf("%d%c",V[i]," \n"[i==n-1]);
    return;
}
void dec(int n) {
    printf("%d\n",n);
    vector<int> V;
    for (int i=0;i<n;i++)
        V.push_back(ran30(1e8));
    sort(V.begin(), V.end(), greater<int>());
    for (int i=0;i<n/10;i++) {
        int j=ran30(n), k=ran30(n);
        swap(V[j], V[k]);
    }
    for (int i=0;i<n;i++)
        printf("%d%c",V[i]," \n"[i==n-1]);
    return;
}

int main() {
    int i,n,m;
	char infile[30]="P_6_15_0.in";
	srand(58111);
for (i=1;i<6;i++) {
    sprintf(infile+7,"%d.in",i);
	freopen(infile,"w",stdout);
	if (i<3) n=10000;
	else n=200000-rand()%10000;
	if (i==1 || i==5) one(n);
	else if (i<4) inc(n);
	else dec(n);
}
	return 0;
}
