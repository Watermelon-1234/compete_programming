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
struct Member {
    int p, c, m;
};
void one(int n) {
    printf("%d\n",n);
    for (int i=0;i<n;i++)
        printf("%d%c",ran30(1e4)+1," \n"[i==n-1]);
    for (int i=0;i<n;i++)
        printf("%d%c",ran30(1e8)," \n"[i==n-1]);
    for (int i=0;i<n;i++)
        printf("%d%c",ran30(1e8)," \n"[i==n-1]);
    return;
}
void small_r(int n) {
    printf("%d\n",n);
    for (int i=0;i<n;i++)
        printf("%d%c",ran30(1e4)+1," \n"[i==n-1]);
    for (int i=0;i<n;i++)
        printf("%d%c",ran30(1000)," \n"[i==n-1]);
    for (int i=0;i<n;i++)
        printf("%d%c",ran30(1000)," \n"[i==n-1]);
    return;
}
void inc(int n) {
    printf("%d\n",n);
    for (int i=0;i<n;i++)
        printf("%d%c",ran30(1e3)+1," \n"[i==n-1]);
    vector<pair<int,int>> V;
    int q=100;
    for (int i=0;i<n;i++)
        V.push_back({q*i+ran30(300),q*i+ran30(300)});
    for (int i=0;i<n/10;i++) {
        int j=ran30(n), k=ran30(n);
        swap(V[j].second, V[k].second);
    }
    random_shuffle(V.begin(), V.end());
    for (int i=0;i<n;i++)
        printf("%d%c",V[i].first," \n"[i==n-1]);
    for (int i=0;i<n;i++)
        printf("%d%c",V[i].second," \n"[i==n-1]);
    return;
}
void dec(int n) {
    printf("%d\n",n);
    for (int i=0;i<n;i++)
        printf("%d%c",ran30(1e3)+1," \n"[i==n-1]);
    vector<pair<int,int>> V;
    int q=100;
    for (int i=0;i<n;i++)
        V.push_back({q*i+ran30(300),q*(n-i)+ran30(300)});
    for (int i=0;i<n/10;i++) {
        int j=ran30(n), k=ran30(n);
        swap(V[j].second, V[k].second);
    }
    random_shuffle(V.begin(), V.end());
    for (int i=0;i<n;i++)
        printf("%d%c",V[i].first," \n"[i==n-1]);
    for (int i=0;i<n;i++)
        printf("%d%c",V[i].second," \n"[i==n-1]);
    return;
}

int main() {
    int i,n,m;
	char infile[30]="P_6_22_0.in";
	srand(58111);
for (i=1;i<6;i++) {
    sprintf(infile+7,"%d.in",i);
	freopen(infile,"w",stdout);
	n=1e5-rand()%1000;
	if (i==1) one(1000);
    else if (i==2) one(n);
	else if (i==3) small_r(n);
    else if (i==4) inc(n);
	else dec(n);
}
	return 0;
}
