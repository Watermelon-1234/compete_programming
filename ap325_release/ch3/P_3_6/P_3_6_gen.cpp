#include <bits/stdc++.h>
using namespace std;
#define N 1000010
pair<int,int> a[N]; // (c,h)

int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}

// k = no of tree which cannot be removed, not necessary
void one(int n, int l, int k, int hard) {
    int i,j, avg=2*l/(k+1);
    set<int> S;
    int t;
    a[0].first=0; a[k+1].first=l;
    for (i=1;i<=k;i++) {
        do t=ran30(l-2)+1;
        while (! ((S.insert(t)).second));
        a[i].first=t;
    }
    sort(a+1,a+k+1);
    for (i=1;i<=k;i++) {
        a[i].second=max(a[i].first-a[i-1].first, a[i+1].first-a[i].first)+1;
    }
    int left=0, right=0;
    if (hard) { // add hard case, [k+1: k+hard]
        for (i=1;i<=k && a[i].first+hard>=a[i+1].first ;i++) ;
        left=a[i].first; right=a[i+1].first;
        int d=(right-left)/(hard+1);
        int p=left+d,q=right-d;
        for (i=k+1; i<=k+hard;i++) {
            if ((i&1) != (k&1)) {
                a[i].first=p;
                a[i].second=q-p;
                p+=d;
            }
            else {
                a[i].first=q;
                a[i].second=q-p;
                q-=d;
            }
        }
        //fprintf(stderr,"[%d,%d]:%d ", left, right,d);
        //for (i=k+1;i<=k+hard;i++) fprintf(stderr,"(%d,%d)",a[i].first,a[i].second);
    }
    avg=2*l/(n-hard);
    for (i=k+hard+1;i<=n;i++) {
        a[i].second=ran30(avg)+1;
        do
            do t=ran30(l-2)+1; while (t>left && t<right);
        while (!((S.insert(t)).second));
        a[i].first=t;
    }
    sort(a+1, a+n+1);
    printf("%d %d\n",n,l);
    assert(a[1].first>0 && a[n].first<l);
    for (i=1;i<n;i++) {
        assert(a[i].first!=a[i+1].first);
        printf("%d ",a[i].first);
    }
    printf("%d\n",a[n].first);
    for (i=1;i<n;i++) {
        printf("%d ",a[i].second);
    }
    printf("%d\n",a[n].second);
    return;
}

int main()
{
	int i,n,L;
	char infile[30]="P_3_6_0.in";
	srand(5813);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
	fprintf(stderr,"%s;", infile);
	n=100000-rand()%1000;
    L=50000000-rand()%100;
    one(n,L,i*800,80000);
}
	return 0;
}
