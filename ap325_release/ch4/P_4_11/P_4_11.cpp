//P4-11 union of segments, using struct
#include <bits/stdc++.h>
using namespace std;
#define N 100010
struct Seg {
    int left, right;
};
bool cmp(Seg p, Seg q) {
    return p.left < q.left;
}
int main() {
	int n, total=0; // total length
	Seg s[N];
	scanf("%d",&n);
	for (int i=0; i<n; i++)
		scanf("%d%d", &s[i].left, &s[i].right);
	sort(s, s+n, cmp); // sort by left
	Seg last = s[0]; // last segment in the union
	for (int i=1; i<n; i++) { // insert each segment
		if (s[i].left > last.right) { // disjoint
			total += last.right - last.left;
			last = s[i];
			continue;
		}
		// else part, merge last and s[i]
        last.right = max(last.right, s[i].right);
	}
	total += last.right - last.left; // don't forget
	printf("%d\n",total);
	return 0;
}
