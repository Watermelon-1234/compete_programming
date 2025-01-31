// demo pq
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[10]={1,4,1,3,8,5,4,9,8,7}, n=10;
    for (int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\nIteratvely insert and report max\n");
    priority_queue<int> pq;
    for (int i=0;i<n;i++) {
        pq.push(a[i]);
        printf("%d ",pq.top());
    }
    printf("\n");
    int sum=0;
    while (!pq.empty()) {
        sum+=pq.top();
        pq.pop();
    }
    printf("Delete all and sum=%d\n",sum);
    printf("PQ of struct, top is smallest, insert backward\n");
    priority_queue<pair<int,int>> pq2; // (value, index)
    for (int i=n-1;i>=0;i--) {
        pq2.push({-a[i],i}); // push minus value
        printf("a[%d]=%d, ", pq2.top().second, -pq2.top().first);
    }
    printf("\n");
    return 0;
}
