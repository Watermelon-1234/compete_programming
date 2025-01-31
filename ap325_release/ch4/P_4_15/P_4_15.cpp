// P_4_15 closest pair, sweep line, L1 distance
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 100010
#define oo 200000001
struct Point {
	int x,y;
};
bool less_x(Point &s, Point &t) {
	return s.x < t.x;
}

int main() {
    int n;
    scanf("%d",&n);
	Point p[N];
    for (int i=0;i<n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    sort(p, p+n, less_x); // sort by x
    multimap<int,int> mm; // (y,x), sort by y
    int min_d = oo; //min distance
    // for each point from left to right
    for (int i=0;i<n; i++) {
        // check [p.y-d, p.y+d]
        auto it=mm.lower_bound(p[i].y - min_d);
        while (it!=mm.end() && it->first <= p[i].y+min_d) {
            if (it->second < p[i].x - min_d) {
                it=mm.erase(it); // x too small, out of date
                continue;
            }
            min_d = min(min_d, \
                    abs(p[i].x-it->second)+abs(p[i].y-it->first));
            it++;
        }
        mm.insert({p[i].y,p[i].x});
    }
    printf("%d\n",min_d);
    return 0;
}
