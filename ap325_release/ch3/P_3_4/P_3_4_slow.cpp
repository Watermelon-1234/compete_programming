// P_3_4, naive method, check one by one
#include <bits/stdc++.h>
#define N 200010
#define oo 10000001
int n,a[N];
int main() {
    int i,j;
    long long total=0; // total distance
	scanf("%d",&n);
	for (i=1; i<=n; i++)
        scanf("%d", &a[i]);
    a[0]=(oo <<1);
 	for (i=1; i<=n; i++) {
        // binary search [left,right) to find last >a[i]+w[i]
	    int t=a[i];
	    for (j=i-1; a[j]<=t; j--);
        total += i - j; // add to solution
	}
	printf("%lld\n",total);
    return 0;
}
