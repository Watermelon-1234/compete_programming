//P4-13 max subarray, O(n^2) method
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
	LL n, max_sum=0; // allow zero
	scanf("%lld",&n);
    LL a[100010];
    a[0]=0;
	for (int i=1; i<=n; i++) {
		scanf("%lld", a+i);
	}
	for (int i=1; i<=n; i++)
		a[i]+=a[i-1];
    for (int i=0; i<n;i++) for (int j=i; j<=n;j++) {
        max_sum=max(max_sum,a[j]-a[i]);
    }
	printf("%lld\n",max_sum);
	return 0;
}
