// P-6-11 Catalan number // top-down
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P 1000000009
ll memo[101]={0};
ll cat(int n) {
    if (memo[n]>=0) return memo[n];
    ll sum=0;
    for (int i=0; i<n;i++) {
        ll t=cat(i)*cat(n-1-i)%P;
        sum = (sum+t)%P;
    }
    return memo[n]=sum;
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<=n;i++)
        memo[i]=-1;
	memo[0]=1;
	printf("%lld\n",cat(n));
    return 0;
}
