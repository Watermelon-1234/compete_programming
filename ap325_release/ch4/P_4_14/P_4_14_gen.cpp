#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> V;
void one(int n, int r) {
    int i,j,k;
    printf("%d\n",n);
    for (i=0;i< n-1;i++)
        printf("%d ",rand()%r);
    printf("%d\n",rand()%r);
    for (i=0;i< n-1;i++)
        printf("%d ",rand()%r);
    printf("%d\n",rand()%r);
    return;
}

void dec(int n) {
    int i,j,k=2e8/n;
    printf("%d\n",n);
    V.clear();
    for (i=0;i<n;i++) V.push_back({i*k+rand()%k, 3e8-i*k+rand()%k*3});
    random_shuffle(V.begin(),V.end());
    for (i=0;i< n-1;i++)
        printf("%d ",V[i].first);
    printf("%d\n",V[i].first);
    for (i=0;i< n-1;i++)
        printf("%d ",V[i].second);
    printf("%d\n",V[i].second);
    return;
}
int main() {
    int n, i, j;
	char infile[30]="P_4_14_0.in";
	srand(5817);
    for (i=1;i<6;i++) {
        infile[7]='0'+i;
        freopen(infile,"w",stdout);
        if (i<3) one(1e5,1e4);
        else if (i<4) one(100000-i*100, 1e9);
        else dec(100000-i);
    }

	return 0;
}

