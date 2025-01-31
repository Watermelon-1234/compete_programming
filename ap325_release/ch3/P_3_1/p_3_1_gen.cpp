#include <bits/stdc++.h>
using namespace std;
#define N 200010

int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}
vector<int> child[N];
int lab[N], p[N];

void perm(int n) {
    for (int i=0;i<n;i++) lab[i]=i+1;
    //return;
    random_shuffle(lab,lab+n);
    return;
}
// a tree with path f
void tree(int n,int f) {
	int i,j;
	perm(n);
	p[lab[0]]=-1;
	for (i=1;i<f;i++) p[lab[i]]=lab[i-1];
	for (;i<n;i++) {
        j=ran30(i);
        p[lab[i]]=lab[j];
	}
    for (i=1;i<=n;i++) child[i].clear();
	for (i=1;i<=n;i++)
        if (p[i]>=1)
            child[p[i]].push_back(i);
    printf("%d\n",n);
    for (i=1;i<=n;i++) {
        printf("%d",(int)child[i].size());
        for (int e:child[i])
            printf(" %d",e);
        printf("\n");
    }
}

int main()
{
	int i,n,L;
	char infile[30]="P_3_1_0.in", outfile[30]="score_0.in";
	srand(5813);
	//tree(10,1);return 0;
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
    n=100000-rand()%1000;
    tree(n,(i<3)? 10: 20000+rand()%5000);
}
	return 0;
}
