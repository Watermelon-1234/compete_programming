// P-6-13 min cost of k-domination
// p[i]= min cost to cover [1..i] and choosing i
// p[i] = c[i]+min{p[j]: j>i-2k-2}; and p[i]=c[i] for i<=k+1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200005
int main() {
    int n,k;
    int c[N];
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; i++)
        scanf("%d", &c[i]);
    int p[N];
    deque<int> minq; // index of p[], increasing
    p[1]=c[1];
    minq.push_back(1);
    for (int i=2; i<=n; i++) {
        if (i<=k+1)
            p[i]=c[i];
        else {
            if (minq.front()<i-2*k-1)
                minq.pop_front();
            p[i] = p[minq.front()] + c[i];
        }
        // pop larger and push itself
        while (!minq.empty() && p[minq.back()]>=p[i])
            minq.pop_back();
        minq.push_back(i);
    }
    printf("%d\n", *min_element(p+n-k, p+n+1));
    return 0;
}
