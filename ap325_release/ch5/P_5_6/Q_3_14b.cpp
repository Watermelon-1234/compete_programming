// Let F be the maximum of a set of linear function. Find F()
// y=ax+b
// algorithm: divide and conquer
#include <bits/stdc++.h>
using namespace std;
#define oo 1000000
#define N 500000
using namespace std;
typedef long long LL;

pair<int,int> line[N];
int point[N];
int n,m;

// for line [l1,r1), point [l2,r2)
// assuming no same slop
LL dc(int l1,int r1,int l2,int r2) {
    LL y,maxy;
    int mid=(l2+r2)>>1,i,j,t;
    if (l2>=r2) return 0;
    maxy=LLONG_MIN;
    assert(l1<r1);
    for (i=l1;i<r1;i++) {
        y=(LL)point[mid]*line[i].first+(LL)line[i].second;
        if (maxy<y) {maxy=y;t=i;}
    }
    return maxy+dc(l1,t+1,l2,mid)+dc(t,r1,mid+1,r2);
}

int main() {
    LL p;
    int i,j;
    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++) {
        scanf("%d%d",&line[i].first,&line[i].second);
    }
    for (i=0;i<m;i++) scanf("%d",point+i);
    sort(line,line+n);
    sort(point,point+m);
    //for (i=0;i<n;i++) printf("(%d,%d),",line[i].first,line[i].second);
    for (i=j=0;i<n;i++) {
        if (line[i].first==line[j].first) {
            line[j]=line[i];
        }
        else line[++j]=line[i];
    }
    n=j+1;
    //for (i=0;i<n;i++) printf("(%d,%d),",line[i].first,line[i].second);
   printf("%lld\n",dc(0,n,0,m));
    return 0;
}
