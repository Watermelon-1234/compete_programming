//P-4-14 2d maximal points backward sweep O(nlogn)
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, total=0; // num of maximal points
	scanf("%d",&n);
	vector<pair<int,int>> V;
	for (int i=0; i<n; i++) {
		int x;
        scanf("%d", &x);
        V.push_back({-x,0}); // change sign for large to small
	}
	for (int i=0; i<n; i++) {
        scanf("%d", &V[i].second);
	}
	sort(V.begin(), V.end());
	int max_y = -1; // max y value so far
	for (auto p: V) {
		int y = p.second;
        if (y > max_y) { // maximal point
            total++;
            max_y = y;
        }
	}
	printf("%d\n",total);
    return 0;
}
