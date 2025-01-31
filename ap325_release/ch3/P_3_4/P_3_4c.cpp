// p_3_4c, using multimap
#include <bits/stdc++.h>
using namespace std;
#define N 300010
#define oo 10000001
int a[N];
int main() {
    int i,n;
    long long total=0; // total distance
	scanf("%d",&n);
	a[0]=oo;
	for (i=1; i<=n; i++) {
        scanf("%d",&a[i]);
	}
	multimap<int,int> M; //(a[i],i) of unsolved
	for (i=n; i>=0; i--) {
        auto it=M.begin();
        // find the whose solution is i
        while (it!=M.end()&& it->first<a[i]) {
            total += it->second - i; // add distance
            it=M.erase(it); // erase and point to next
        }
        M.insert({a[i],i});
	}
	printf("%lld\n",total);
    return 0;
}
