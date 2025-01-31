//P-5-2 max subarray, DaC, O(n)
#include <bits/stdc++.h>
#define N 200020
using namespace std;
typedef long long LL;
LL psum[N]; // prefix-sum
struct Rdata {
    // max-sum, max prefix-sum, max suffix-sum
    LL msum, lmax, rmax;
};

// return max in [le, ri),
Rdata subarr(LL a[], int le, int ri) {
    if (le+1 == ri) {
        LL t = max(a[le],(LL)0);
        return {t, t, t};
    }
    int mid=(le+ri)/2;
    // recursively solve left and right parts
    Rdata left=subarr(a, le, mid), right=subarr(a, mid, ri);
    Rdata my;
    my.lmax=max(left.lmax, psum[mid-1]-psum[le-1]+right.lmax);
    my.rmax=max(right.rmax, psum[ri-1]-psum[mid-1]+left.rmax);
    my.msum=max(left.msum, right.msum);
    // find largest sum cross middle
    my.msum=max(my.msum, left.rmax+right.lmax);
    return my;
}

int main() {
	LL n, a[N];
	scanf("%lld",&n);
	a[0]=0, psum[0]=0;
	for (int i=1; i<=n; i++) {
		scanf("%lld", &a[i]);
		psum[i]=psum[i-1]+a[i];
	}
	printf("%lld\n", subarr(a, 1, n+1).msum);
	return 0;
}
