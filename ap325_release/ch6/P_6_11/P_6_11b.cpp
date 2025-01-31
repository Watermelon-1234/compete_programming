// P-6-11 Catalan number // bottom up
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P 1000000009

int main() {
	int n;
	scanf("%d",&n);
	ll cat[101];
	cat[0]=1;
	for (int i=1;i<=n;i++) {
        cat[i]=0;
        for (int j=0; j<i; j++) {
            cat[i] = (cat[i] + cat[j]*cat[i-1-j]%P)%P;
        }
    }
	printf("%lld\n",cat[n]);
    return 0;
}
