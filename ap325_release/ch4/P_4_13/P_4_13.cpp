//P4-13 max subarray, O(n)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
	LL n, max_sum=0; // allow zero
	LL p_max=0; // prefix minimum
	scanf("%lld",&n);
	for (int i=0; i<n; i++) {
        LL p;
		scanf("%lld", &p);
        p_max=(p_max>0)? p_max+p : p;
        max_sum = max(max_sum, p_max);
	}
	printf("%lld\n",max_sum);
	return 0;
}
