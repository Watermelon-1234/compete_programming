// compare pq and multiset
#include <bits/stdc++.h>
using namespace std;
#define N 1000000
multiset<int,greater<int>> S;
priority_queue<int> pq;

int main() {
    int a[N], n=N;
    for (int i=0;i<n;i++) a[i]=rand();

    clock_t t1, t2;
    long long sum=0;
    t1=clock();
    for (int i=0;i<n;i++) {
        S.insert(a[i]);
        sum+=*S.begin();
    }
    while (!S.empty()) {
        sum+=*S.begin();
        S.erase(S.begin());
    }
    printf("%lld\n",sum);
    t2=clock();
    printf("set takes %f sec\n", (float)(t2-t1)/CLOCKS_PER_SEC);
    sum=0;
    t1=clock();
    for (int i=0;i<n;i++) {
        pq.push(a[i]);
        sum+=pq.top();
    }
    while (!pq.empty()) {
        sum+=pq.top();
        pq.pop();
    }
    printf("%lld\n",sum);
    t2=clock();
    printf("PQ takes %f sec\n", (float)(t2-t1)/CLOCKS_PER_SEC);
    return 0;
}
