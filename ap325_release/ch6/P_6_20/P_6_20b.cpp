// hypercube max weight path from 0 to 2^n-1
// bottom-up approach, BFS
#include <bits/stdc++.h>
using namespace std;
#define N 1000000
int c[N],w[N];

int main() {
	int n;
	scanf("%d",&n);//printf("%d %d %d\n",n,s,t);
	int m=1<<n;
    for (int i=0;i<m;i++) scanf("%d",&w[i]);
    for (int i=0;i<m;i++) c[i]=0;
	queue<int> que;
	bool inq[N]={0};
	que.push(0); // starting node
	inq[0]=true;
	while (!que.empty()) {
        int v=que.front();
        que.pop();
        c[v]+=w[v];
        for (int i=0;i<n;i++) { // for each bit i=0
            int bit_i=(1<<i);
            if ((v & bit_i)==0) {
                int u = v | bit_i; // out-neighbor
                c[u]=max(c[u],c[v]);
                if (inq[u]==false) {
                    inq[u]=true;
                    que.push(u);
                }
            }
        }
	}
    printf("%d\n",c[m-1]);
    return 0;
}

