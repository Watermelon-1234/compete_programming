// P-5-6. Let F be the maximum of a set of linear function.
// Find F(c[1]) + F(c[2])+...F(c[m])
// algorithm: divide and conquer
#include <bits/stdc++.h>
using namespace std;
#define N 100010
using namespace std;
typedef long long LL;
struct Line {
    int a, b; // y=ax+b
} line[N];
// compare by slope first
bool cmp(Line p, Line q) {
    if (p.a == q.a)
        return p.b < q.b;
    return p.a < q.a;
}
int point[N];

// for line [l1,r1), point [l2,r2)
LL dc(int l1,int r1,int l2,int r2) {
    if (l2 >= r2) return 0; // no points
    int mid = (l2+r2)>>1;
    // find max y of the middle point
    LL max_y = LLONG_MIN, who;
    for (int i=l1; i<r1; i++) {
        LL y=(LL)point[mid]*line[i].a+(LL)line[i].b;
        if (max_y < y) {
            max_y = y;
            who = i;
        }
    }
    // left side need only smaller slope, right side larger slope
    return max_y + dc(l1,who+1,l2,mid) + dc(who,r1,mid+1,r2);
}

int main() {
    int i,m,n;
    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++) {
        scanf("%d%d",&line[i].a,&line[i].b);
    }
    for (i=0;i<m;i++) scanf("%d",point+i);
    sort(line, line+n, cmp);
    sort(point, point+m);
    printf("%lld\n",dc(0,n,0,m));
    return 0;
}
