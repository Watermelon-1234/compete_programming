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
// x^y
ll bexp(ll x, int y) {
    if (y==0) return 1;
    ll t=bexp(x,y/2);
    if (y&1) return (((t*t)%P)*x)%P;
    return (t*t)%P;
}
// find inverse
ll inv(int n) {
    return bexp(n, P-2);
}
// cn=C(2n,n)/(n+1)
ll cat2(int n) {
    ll cn=n+2;
    for (int i=n+3; i<=2*n; i++)
        cn = (cn*i)%P;
    for (int i=2;i<=n; i++)
        cn = (cn*inv(i))%P;
    return cn;
}

int main() {
	int n, c;

	scanf("%d",&n);
	for (int i=0;i<=n;i++) memo[i]=-1;
	memo[0]=1;
	printf("%d\n",c=(int)cat(n));
	fprintf(stderr,"%d = %d\n",c, (int)cat2(n));
    return 0;
}
