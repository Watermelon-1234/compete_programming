// p-5-4 inversion number O(n^2)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	int n, a[100010];
	scanf("%d", &n);
	for (int i=0; i<n; i++)
        scanf("%d", a+i);
	LL inv=0;
	for (int i=0;i<n;i++) for (int j=i+1;j<n;j++)
        if (a[i]>a[j]) inv++;
    printf("%lld\n", inv);
	return 0;
}
