// P-4-11, union of segment, sweep line
#include <bits/stdc++.h>
using namespace std;
#define N 100010
int main() {
	int i,n,total;
	pair<int,int> s[N], cur;
	scanf("%d",&n);
	for (i=0; i<n; i++)
		scanf("%d%d", &s[i].first, &s[i].second);
	sort(s, s+n);
	total = 0;
	cur = s[0]; int n_seg=1, maxlen=0;
	for (i=1; i<n; i++) {
		if (s[i].first > cur.second) { // disjoint
			total += cur.second - cur.first;
			maxlen = max(maxlen, cur.second - cur.first);
			cur = s[i];
			n_seg++;
			continue;
		}
		// else part, merge cur and s[i]
        cur.second = max(cur.second, s[i].second);
	}
	total += cur.second - cur.first;
	printf("%d\n",total);
	fprintf(stderr,"n_seg=%d, longest=%d\n", n_seg, maxlen); // for checking
	return 0;
}
