// P_4_3, min waiting time, sorting+greedy
#include <bits/stdc++.h>
using namespace std;
#define N 100010
int main() {
    int n, job[N];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&job[i]);
    sort(job, job+n); // sort from small to large
    long long int comp=0, total=0;
    for (int i=0; i<n; i++) {
        comp += job[i]; // completion time of i
        total += comp; // total completion time
    }
    printf("%lld\n",total);
    return 0;
}
