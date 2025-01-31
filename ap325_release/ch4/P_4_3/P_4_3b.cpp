// P_4_3, min waiting time, sorting+greedy
// another way
#include <bits/stdc++.h>
using namespace std;
#define N 100010
int main() {
    int n, job[N];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&job[i]);
    sort(job, job+n); // sort from small to large
    long long int total=0;
    for (int i=0;i<n;i++)
        total += (long long)(n-i)*job[i];
    printf("%lld\n",total);
    return 0;
}
