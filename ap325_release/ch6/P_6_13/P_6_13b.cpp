// P-6-13 min cost of k-domination O(n), no STL
// p[i]= min cost to cover [1..i] and choosing i
// p[i] = c[i]+min{p[j]: j>i-2k-2}; and p[i]=c[i] for i<=k+1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200005
int main() {
    int n,k,c[N],p[N];
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; i++)
        scanf("%d", &c[i]);
    // deque, index of p[], increasing p[]
    int minq[N], head=0, tail=0;
    p[1]=c[1];
    minq[tail++]=1; // push_back
    for (int i=2; i<=n; i++) {
        if (i<=k+1)
            p[i]=c[i];
        else {
            if (minq[head]<i-2*k-1)
                head++; // out of range, pop_front
            p[i] = p[minq[head]] + c[i];
        }
        // pop larger and push itself
        while (head<tail && p[minq[tail-1]]>=p[i])
            tail--;
        minq[tail++]=i; // push i
    }
    // find answer: min p[n-k:n]
    int ans=p[n-k];
    for (int i=n-k+1; i<=n; i++)
        if (p[i]<ans) ans=p[i];
    printf("%d\n", ans);
    return 0;
}
