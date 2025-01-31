//P-5-2 max subarray, DaC, O(nlogn)
#include <bits/stdc++.h>
#define N 200020
using namespace std;
typedef long long LL;

// max subarray in [le, ri)
LL subarr(LL a[], int le, int ri) {
    if (le >= ri) return 0;
    if (le+1 == ri) return max(a[le],(LL)0);
    int mid=(le+ri)/2;
    // recursively solve left and right parts
    LL largest=max(subarr(a, le, mid), subarr(a, mid, ri));
    // find largest sum cross middle
    LL lmax=0, rmax=0;
    // max suffix sum of the left
    for (LL sum=0, i=mid-1; i>=le; i--) {
        sum += a[i];
        lmax=max(lmax, sum);
    }
    // max prefix sum of the right
    for (LL sum=0, i=mid; i<ri; i++) {
        sum += a[i];
        rmax=max(rmax, sum);
    }
    return max(largest, lmax+rmax);
}

int main() {
	LL n, a[N];
	scanf("%lld",&n);
	for (int i=0; i<n; i++)
		scanf("%lld", &a[i]);
	printf("%lld\n", subarr(a, 0, n));
	return 0;
}
