// P_3_6, n^2 method, mark removed tree
#include <stdio.h>
#define N 100010
#define oo 1000000000

int main() {
    int n, l, c[N], h[N]; // center and height;
    int total=0, high=0; // total removed and max height
    scanf("%d%d",&n,&l);
    // set left and right boundaries
    c[0]=0, c[n+1]=l;
    h[0]=h[n+1]=oo;
    for (int i=1; i<=n; i++)
        scanf("%d", &c[i]);
    for (int i=1; i<=n; i++)
        scanf("%d", &h[i]);
    // repeat until no tree can be removed
    while (1) {
        int i;
        for (i=1; i<=n; i++) { // check each tree
            if (h[i]==0) continue; // already removed
            int prev=i-1, next=i+1;
            while (h[prev]==0) prev--; // previous remaining tree
            while (h[next]==0) next++; // next remaining tree
            if (c[i]-h[i]>=c[prev] || c[i]+h[i]<=c[next])
                break; // removable
        }
        if (i>n) break; // no tree can be removed
        total++;
        if (h[i] > high) high=h[i];
        h[i]=0;
    }
    printf("%d\n%d\n", total, high);
    return 0;
}
