
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

void perm(int n, bool ifperm) {
    for (int i=0;i<n;i++) lab[i]=i+1;
    if (!ifperm) return;
    random_shuffle(lab,lab+n);
    return;
}
bool cmp(EDGE &e1, EDGE &e2) {
    return e1.v < e2.v;
}
void one(int n, bool ifperm) {
	int i,j;
	perm(n, ifperm);
	vector<EDGE> edge;
	for (i=1;i<n;i++) {
        j=ran30(i);
        edge.push_back({lab[j],lab[i], rand()%1000+1});
	}
	random_shuffle(edge.begin(), edge.end());
	printf("%d\n",n);
	for (i=0; i<n; i++)
        printf("%d%c", ran30(1000)+1, " \n"[i==n-1]);
	for (auto e: edge) {
        if (rand()&1) printf("%d %d\n", e.u, e.v);
        else printf("%d %d\n",e.v, e.u);
	}
	return;
}
// a random tree with several path length =f
void ptree(int n,int f) {
	int i,j;
	perm(n,true);
	vector<EDGE> edge;
	for (i=1;i<f;i++)
        edge.push_back({lab[i-1],lab[i],rand()%1000+1});
	for (;i<n-f;i+=f) {
        int v=ran30(i);
        edge.push_back({lab[v],lab[i],rand()%1000+1});
        for (j=1;j<f;j++) {
            edge.push_back({lab[i+j-1],lab[i+j],rand()%1000+1});
        }
	}
	for (;i<n;i++) {
        j=ran30(i);
        edge.push_back({lab[j],lab[i], rand()%1000+1});
	}
	random_shuffle(edge.begin(), edge.end());
	printf("%d\n",n);
	for (i=0; i<n; i++)
        printf("%d%c", ran30(1000)+1, " \n"[i==n-1]);
	for (auto e: edge) {
        if (rand()&1) printf("%d %d\n", e.u, e.v);
        else printf("%d %d\n",e.v, e.u);
	}
	return;
}

int main() {
    int i,n, m, r;
	char infile[30]="P_8_13_0.in";
	srand(58123);
for (i=1;i<6;i++) {
    sprintf(infile+7,"%d.in",i);
	freopen(infile,"w",stdout);
	if (i<=2)
        one(100-rand()%10, false);
    else if (i==3) one(100000-rand()%1000, true);
    else {
        ptree(100000-rand()%1000, 3000*i);
    }
}
return 0;

}
