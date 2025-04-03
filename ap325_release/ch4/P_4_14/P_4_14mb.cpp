//P-4-14 2d maximal points backward sweep O(nlogn)
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, total=0; // num of maximal points
	scanf("%d",&n);
	vector<pair<int,int>> V(n);
	for (int i=0; i<n; i++) {
        scanf("%d", &V[i].first);
	}
	for (int i=0; i<n; i++) {
        scanf("%d", &V[i].second);
	}
	// from x small to large, for same x, y from small to large
	sort(V.begin(), V.end());
	int max_y = -1; // max y value so far
	for (int i=n-1; i>=0; --i) { // backward
        if (V[i].second > max_y) { // maximal point
            total++;
            max_y = V[i].second;
        }
	}
	printf("%d\n",total);
    return 0;
}
