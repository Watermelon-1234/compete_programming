// p-5-4 inversion number DaC O(nlog^2n)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// return the inversion in [le, ri) ans sort them
LL inv(int a[], int le, int ri) {
    if (le+1 >= ri) return 0; // terminal case
    int m = (le+ri)/2;
    // recursively solve the left and the right parts
    LL w=inv(a, le, m) + inv(a, m, ri), cross=0;
    // count a[j]<a[i] for i<m<=j
    int j=m;
    for (int i=le; i<m; i++) {
        while (j<ri && a[j]<a[i]) // until >=a[i]
            j++;
        cross += j - m; // num <a[i]
    }
    sort(a+le, a+ri); // sort before return
    return w + cross;
}

int main() {
	int i, n, ar[100010];
	scanf("%d", &n);
	for (i=0; i<n; i++) scanf("%d", ar+i);
    printf("%lld\n", inv(ar, 0, n));
	return 0;
}
