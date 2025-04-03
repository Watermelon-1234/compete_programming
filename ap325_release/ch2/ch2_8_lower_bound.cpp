// demo lower_bound for struct and pair
#include <bits/stdc++.h>
using namespace std;
#define N 5
struct point {
    int x,y;
};
// compare by only x
bool pcmp(point s, point t) {
    return s.x < t.x;
}
int main() {
    point p[N];
    int n=5;
    for (int i=0;i<n;i++) p[i].x=rand()%10, p[i].y=rand()%10;
    sort(p, p+n, pcmp);
    for (int i=0;i<n;i++) printf("(%d,%d) ",p[i].x, p[i].y);
    printf("\n");
    for (int i=0;i<5;i++) {
        point t={i*3,rand()%10};
        int ndx=lower_bound(p, p+n, t, pcmp) - p;
        if (ndx<n)
            printf("Find >=(%d,%d) at [%d]=(%d,%d)\n", \
                   t.x, t.y, ndx,p[ndx].x, p[ndx].y);
        else
            printf("No one >=(%d,%d)\n",t.x, t.y);
    }
    // for vector
    vector<point> v(p, p+n);
    for (int i=0;i<5;i++) {
        point t={i*3,rand()%10};
        auto q=lower_bound(v.begin(), v.end(), t, pcmp);
        if (q!=v.end())
            printf("Find >=(%d,%d) at [%d]=(%d,%d)\n", \
                   t.x, t.y, q-v.begin(), q->x, q->y);
        else
            printf("No x>=(%d,%d)\n",t.x, t.y);
    }
    // using pair, default compare function
    printf("Compare by x and then y\n");
    vector<pair<int,int>> a;
    for (point e:v) a.push_back({e.x,e.y});
    for (int i=0;i<5;i++) {
        pair<int,int> t={i*3,rand()%10};
        auto q=lower_bound(a.begin(), a.end(), t);
        if (q!=a.end())
            printf("Find >=(%d,%d) at [%d]=(%d,%d)\n", \
                   t.first,t.second, q-a.begin(), q->first, q->second);
        else
            printf("No x>=(%d,%d)\n",t.first, t.second);
    }
    printf("Compare by only x\n");
    for (int i=0;i<5;i++) {
        pair<int,int> t={i*3,rand()%10};
        // set t.second to minimum to ignore comparison of y-value
        auto q=lower_bound(a.begin(), a.end(), make_pair(t.first,-1));
        if (q!=a.end())
            printf("Find >=(%d,%d) at [%d]=(%d,%d)\n", \
                   t.first,t.second, q-a.begin(), q->first, q->second);
        else
            printf("No x>=(%d,%d)\n",t.first, t.second);
    }

    return 0;
}
