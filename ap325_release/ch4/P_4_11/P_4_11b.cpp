//P4-11 union of segments, using pair
#include <bits/stdc++.h>
using namespace std;
#define Left first
#define Right second

int main() {
	int i,n,total;
	vector<pair<int,int>> s;
	scanf("%d",&n);
	for (i=0; i<n; i++) {
        int p, q;
		scanf("%d%d", &p, &q);
        s.push_back({p,q});
	}
	sort(s.begin(), s.end());
	total = 0;
	pair<int,int> last = s[0];
	for (auto seg: s) {
		if (seg.Left > last.Right) { // disjoint
			total += last.Right - last.Left;
			last = seg;
			continue;
		}
		// else part, merge last and s[i]
        last.Right = max(last.Right, seg.Right);
	}
	total += last.Right - last.Left;
	printf("%d\n",total);
	return 0;
}
