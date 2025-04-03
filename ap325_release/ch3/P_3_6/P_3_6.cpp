// P_3_6, O(n) using stack
#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define oo 1000000000

int main() {
    int n,l,i, c[N],h[N];
    int total=0, high=0; // num of removable and max height
    stack<int> S; // the index of remaining trees so far
    scanf("%d%d",&n,&l);
    // oo trees at two boundaries
    c[0]=0;
    h[0]=oo;
    c[n+1]=l;
    h[n+1]=oo;
    for (i=1;i<=n;i++)
        scanf("%d", &c[i]);
    for (i=1;i<=n;i++)
        scanf("%d", &h[i]);
    S.push(0);
    for (i=1;i<=n;i++) { // scan from left to right
        // if i is removable
        if (c[i]-h[i]>=c[S.top()] || c[i]+h[i]<=c[i+1]) {
            total++;
            high = max(high, h[i]);
            // backward check remaining tree in stack
            while (c[S.top()]+h[S.top()]<=c[i+1]) {
                total++; high = max(high, h[S.top()]);
                S.pop();
            }
        } else { // i is not removable
            S.push(i);
        }
    }
    printf("%d\n%d\n", total,high);
    return 0;
}
