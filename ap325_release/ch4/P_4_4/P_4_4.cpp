// P_4_4,activity selection, sorting+greedy
#include <bits/stdc++.h>
using namespace std;
#define N 100010
struct ACT{
    int s,f; // start and finish time
};
// compare finish time
bool cmp(ACT p, ACT q) {
    return p.f<q.f;
}
int main() {
    int n;
    ACT ac[N];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d%d",&ac[i].s, &ac[i].f);
    sort(ac, ac+n, cmp); // sort from small to large
    int endtime=-1, total=0;
    for (int i=0; i<n; i++) {
        if (ac[i].s>endtime) { // compatible
            total++;
            endtime=ac[i].f;
        }
    }
    printf("%d\n",total);
    return 0;
}
