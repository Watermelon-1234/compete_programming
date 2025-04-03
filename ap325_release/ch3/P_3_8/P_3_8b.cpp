// P3-8, O(NlogN) using multiset
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
int seq[MAXN];
multiset<int> S;

int main() {
    int n, L, i,j;
    scanf("%d%d\n", &n, &L);
    for (i=0; i<n; i++) {
        scanf("%d",&seq[i]);
    }
    for (i=0;i<L;i++)
        S.insert(seq[i]);
    int max_diff=*S.rbegin()- *S.begin();
    for (i=L; i<n; i++) { // range is [i-L, i-1]
        S.insert(seq[i]);
        S.erase(S.find(seq[i-L]));
        max_diff=max(max_diff, (*S.rbegin())- (*S.begin()));
    }
    printf("%d\n",max_diff);
    return 0;
}
