// p_5_4_a nlog^2(n) method
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
// binary search the num <x from a[0] to a[len-1]
int bsearch(int a[], int len, int x) {
    if (a[0]>=x) return 0;
    int pos=0;
    for (int jump=len/2; jump>0; jump>>=1) {
        while (pos+jump<len && a[pos+jump]<x)
            pos += jump;
    }
    return pos+1;
}

// interval= [le,ri), return #inversion
LL inv(int ar[], int le, int ri) {
    int i,j,mid = (ri+le)/2; // middle point
    if (le+1 >= ri) return 0; // terminal case
    // recursively solve left and right parts
    LL w = inv(ar, le, mid) + inv(ar, mid, ri), cross=0;
    sort(ar+mid, ar+ri); // sort the right part
    // for each in left, binary search to find #inversion
    for (i=le; i<mid; i++) {
        //cross += bsearch(ar+mid, ri-mid, ar[i]);
        // following is using STL binary search
        cross += lower_bound(ar+mid, ar+ri, ar[i]) - (ar+mid);
    }
    return w + cross;
}
int main() {
	int i, n, ar[100010];
	scanf("%d", &n);
	for (i=0; i<n; i++) scanf("%d", ar+i);
    printf("%lld\n", inv(ar, 0, n));
	return 0;
}
