// p_3_4b, stack
#include <bits/stdc++.h>
using namespace std;
#define N 300010
#define oo 10000001
stack<pair<int,int>> S; // (b[i],i)
int main() {
    int i,bi,n;
    long long total=0; // total distance
	scanf("%d",&n);
	S.push({oo<<1,0});
	for (i=1; i<=n; i++) {
        scanf("%d",&bi);
        // <=bi is useless
        while (S.top().first <= bi)
            S.pop();
        total += i - S.top().second;
        S.push({bi,i});
	}
	printf("%lld\n",total);
    return 0;
}
