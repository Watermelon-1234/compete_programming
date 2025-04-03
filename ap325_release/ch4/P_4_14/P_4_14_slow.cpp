// O(n^2)
#include<bits/stdc++.h>
using namespace std;
#define N 100010

int main() {
    int i,j,n;
	scanf("%d",&n);
	int x[N], y[N];
	for (i=0; i<n; i++) {
        scanf("%d", &x[i]);
	}
	for (i=0; i<n; i++) {
        scanf("%d", &y[i]);
	}
	int total=0;
	// check all pair, same (x,y) take small i
	for (i=0; i<n;i++) {
        for (j=0;j<i;j++) {
            if (x[j]>=x[i] && y[j]>=y[i])
                break;
        }
        if (j<i) continue;
        for (j=i+1; j<n;j++) {
            if (x[j]>=x[i] && y[j]>=y[i] && x[j]+y[j]>x[i]+y[i])
                break;
        }
        if (j>=n) total++;
	}
	printf("%d\n",total);
    return 0;
}
