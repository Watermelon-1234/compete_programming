// P3-7, sum of subarray, positive
#include <bits/stdc++.h>
using namespace std;
#define N 1000010
int a[N];

int main() {
	int n,k;
	long long total=0;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) {
        scanf("%d", &a[i]);
        total+=a[i];
	}
	int left, right,ans=0, sum=0, num=0;
	// sum is for range [j,i]
	// move right one by one
	for (left=0,right=0;right<n;right++) {
        sum+=a[right];
        // move left until sum<=k
        while (sum>k) {
            sum-=a[left];
            left++;
        }
        // check answer
        if (sum>ans) {
            ans=sum;
            num=1;
        }
        else if (sum==ans) num++;
	}
	printf("%d\n%d\n",ans,num);
	fprintf(stderr,"total=%lld, k=%d; %d %d\n",total,k,ans,num);
	return 0;
}
