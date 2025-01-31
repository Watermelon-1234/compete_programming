//P-4-15 closest pair, naive O(n^2)
#include<bits/stdc++.h>
using namespace std;
#define N 100010
int main() {
    int n, x[N], y[N]; // num of maximal points
	scanf("%d",&n);
	for (int i=0; i<n; i++) 
        scanf("%d%d", &x[i], &y[i]);
    int d=2e9;
    for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) {
        int t=abs(x[i]-x[j])+abs(y[i]-y[j]);
        d=min(t,d);
    }
    printf("%d\n",d);
    return 0;
}
