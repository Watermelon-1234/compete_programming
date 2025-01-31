// O(n^2), remove cut tree from array
#include <stdio.h>
#define N 100010
#define oo 1000000000
// return a removable tree; return -1 if none
int removable(int c[], int h[], int k) {
    for (int i=1; i<k-1; i++)
        if ((c[i]-h[i]>=c[i-1]) || (c[i]+h[i]<=c[i+1]))
        return i;
    return -1;
}

int main() {
    int n, l, c[N], h[N]; // center and height
    int total=0, high=0; // total removed and max height
    scanf("%d%d",&n,&l);
    // set left and right boundaries
    c[0]=0, h[0]=oo;
    c[n+1]=l, h[n+1]=oo;
    for (int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for (int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    n += 2; // two boundary
    while (1) {
        int cut = removable(c, h, n); // the previous alive
        if (cut < 0) break;
        total++;
        if (h[cut] > high) high=h[cut];
        // remove cut from array
        for (int i=cut; i<n-1; i++)
            h[i] = h[i+1]; // overwrite by next
        for (int i=cut; i<n-1; i++)
            c[i] = c[i+1];
        n--;
    }
    printf("%d\n%d\n", total, high);
    return 0;
}
