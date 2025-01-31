// tree format
// n
// p[v] v w
#include<bits/stdc++.h>
#define N 200010
using namespace std;
struct EDGE {
    int u,v,w;
};
int lab[N];

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
    random_shuffle(lab,lab+n);
    return;
}

// a random tree with a path length =f
void one(int n,int f) {
	int i,j;
	perm(n);
	vector<EDGE> edge;
	for (i=1;i<f;i++)
        edge.push_back({lab[i],lab[i-1],rand()%100+1});
	for (;i<n;i++) {
        j=f/2+ran30(i-f/2);
        edge.push_back({lab[i],lab[j], rand()%100+1});
	}
	random_shuffle(edge.begin(), edge.end());
	printf("%d\n",n);
	for (auto e: edge) {
        if (rand()&1)
            printf("%d %d %d\n",e.u,e.v,e.w);
        else
            printf("%d %d %d\n",e.v,e.u,e.w);
	}
	return;
}

int main() {
    int i,n, m, r;
	char infile[30]="P_8_1_0.in";
	srand(58123);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
	if (i<3)
        n=100-rand()%20;
    else {
        n=50000-ran30(10000);
    }
    one(n,(i==5)? n/2: n/10);
}
return 0;

}
