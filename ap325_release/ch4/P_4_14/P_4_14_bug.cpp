//P-4-14 2d maximal points (forward sweep + stack) O(nlogn)
#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define oo 1000000001
struct Point {
    int x, y;
};
bool less_x(Point a, Point b) {
    return a.x < b.x;
}
int main() {
    int n;
	scanf("%d",&n);
	Point p[N];
	for (int i=0; i<n; i++)
        scanf("%d", &p[i].x);
	for (int i=0; i<n; i++)
        scanf("%d", &p[i].y);
	sort(p, p+n, less_x); // sort from left to right
	stack<int> S;// keep y-value of current maximal
	S.push(oo); // a dummy maximal (-oo, oo)
	for (int i=0; i<n; ++i) { // x from small to large
        while (p[i].y >= S.top())
            S.pop(); // delete smaller y
        S.push(p[i].y);
	}
	printf("%d\n",(int)S.size()-1);
    return 0;
}
