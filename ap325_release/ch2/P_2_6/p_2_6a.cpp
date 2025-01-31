// p_2_6 find a+b=k
#include <bits/stdc++.h>
using namespace std;
#define N 100010
int a[N], b[N];

int main() {
    int m, n, k,i;
    scanf("%d %d %d", &m,&n,&k);
    //fprintf(stderr,"%d, %d, %d\n",m,n,k);
    for (i=0;i<m;i++) scanf("%d", a+i);
    for (i=0;i<n;i++) scanf("%d", b+i);
    sort(a, a+m); // sort a from small to large
    sort(b, b+n); // sort b from small to large
    int j=n-1; // index of b, from n-1 to 0
    int ans=0;
    for (i=0; i<m; i++) { // each a[i]
        while (j>0 && b[j]>k-a[i]) // backward linear search
            j--;
        if (a[i]+b[j]==k) {
            ans++;
            //fprintf(stderr,"(%d, %d)",a[i],b[j]);
        }
    }
    printf("%d\n",ans);
	return 0;
}
