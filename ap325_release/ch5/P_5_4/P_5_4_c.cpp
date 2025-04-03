// p-5-4 inversion number DaC O(nlogn)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// return the inversion in [le, ri) and sort the array
LL inv(int a[], int le, int ri) {
    if (le+1 >= ri) return 0; // terminal case
    int m = (le+ri)/2;
    // recursively solve the left and the right parts
    LL w=inv(a, le, m) + inv(a, m, ri), cross=0;
    // merge the two sorted lists
    int temp[ri-le], j=m, k=0;
    for (int i=le; i<m; i++) {
        while (j<ri && a[j]<a[i])
            temp[k++] = a[j++];
        temp[k++] = a[i];
        cross += j - m; // num <a[i]
    }
    // the remaining of right part are already on position
    // copy back to a
    for (k=le; k<j; k++)
        a[k] = temp[k-le];
    return w + cross;
}

int main() {
	int i, n, ar[100010];
	scanf("%d", &n);
	for (i=0; i<n; i++) scanf("%d", ar+i);
    printf("%lld\n", inv(ar, 0, n));
	return 0;
}
