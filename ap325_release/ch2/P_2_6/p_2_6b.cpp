// p_2_6b find a+b=k, using set
#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, k,i,t;
    scanf("%d %d %d", &m,&n,&k);
    set<int> S;
    // read A into set
    for (i=0;i<m;i++) {
        scanf("%d", &t);
        S.insert(t);
    }
    int ans=0;
    for (i=0;i<n;i++) { // for each t in B
        scanf("%d", &t);
        if (S.find(k-t)!=S.end()) // search k-t in A
            ans++;
    }
    printf("%d\n",ans);
	return 0;
}
