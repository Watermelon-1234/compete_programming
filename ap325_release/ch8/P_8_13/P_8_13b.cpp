// dominating set of a tree
#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define oo 1000000000
vector<int> adj[N];
int dom(int n,int p[], int w[], int q[]); //find min domination set of a tree

int main() {
    int parent[N];
    int weight[N];
    int mis,i,j,n,ii,nn;
    scanf("%d",&n);
    for (i=1; i<=n; i++)
        scanf("%d",&weight[i]);
    for (i=1;i<n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    parent[1] = 0;
    int que[N], head=0, tail=1;
    que[0]=1;
    while (head < tail ) {
        int v=que[head++];
        for (int u: adj[v]) {
            if (u==parent[v]) continue;
            parent[u]=v;
            que[tail++]=u;
        }
    }
    assert(tail==n);
    mis=dom(n,parent,weight,que);
    printf("%d\n",mis);
    return 0;
}

// f1(i) the sol of the subtree rooted at i with i
//f0a(i) is the sol without i but i is dominated
// f0b(i) without i and i is either dominated or not
int dom(int n,int p[], int w[], int q[]) {
	int f1[N],f0a[N], f0b[N];
	int mindif[N]; //min f1-f0 for all child
	int total,mymin,mymin0;
	// f2 is the max ind set with i and f1 is mis without i
	int i,parent;
	for (i=1;i<=n;i++) f0a[i]=f0b[i]=0;
	for (i=1;i<=n;i++) f1[i]=w[i];
	for (i=1;i<=n;i++) mindif[i]=oo;
	for (i=n-1; i>=0; i--) {
		int v=q[i];
		if (mindif[v]>0) f0a[v]+=mindif[v];
		mymin = min(f1[v],f0a[v]);
		mymin0 = min(mymin, f0b[v]);
		parent = p[v];
		if (parent==0) return mymin;
		f1[parent] += mymin0;
		f0a[parent] += mymin;
		f0b[parent] += mymin;
		mindif[parent] = min(mindif[parent],f1[v]-f0a[v]);
	}
    return total;
}
