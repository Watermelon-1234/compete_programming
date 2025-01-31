// p_3_4a, stack for index
#include <bits/stdc++.h>
using namespace std;
#define N 300010
#define oo 10000001
int a[N];
stack<int> S; // for index
int main() {
    int i,n;
    long long total=0; // total distance
	scanf("%d",&n);
	S.push(0);
	a[0]=oo;
	for (i=1; i<=n; i++) {
        scanf("%d",&a[i]);
	}
	for (i=1; i<=n; i++) {
        while (a[S.top()] <= a[i])
            S.pop();
        total += i - S.top();
        S.push(i);
	}
	printf("%lld\n",total);
    return 0;
}
