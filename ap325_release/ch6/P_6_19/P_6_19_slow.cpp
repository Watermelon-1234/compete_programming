// P_6-19 slow method
#include <cstdio>
typedef long long LL;

int step(LL n) {
    int d=9;
    while (n) {
        if (n%10>d) return 0;
        d = n%10;
        n /= 10;
    }
    return 1;
}

int main() {
	LL n,i,ans=0;
	scanf("%lld",&n);
	for (ans=0,i=1; i<=n; i++)
        ans += step(i);
    printf("%lld\n",ans);
	return 0;
}
