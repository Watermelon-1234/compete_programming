//P4-12 max price difference, O(n)
#include <bits/stdc++.h>
using namespace std;
#define oo 1000001

int main() {
	int n, max_diff=0; // allow zero
	int p_min=oo; // prefix minimum
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
        int p;
		scanf("%d", &p);
        max_diff=max(max_diff, p - p_min);
        p_min = min(p_min, p);
	}
	printf("%d\n",max_diff);
	return 0;
}
