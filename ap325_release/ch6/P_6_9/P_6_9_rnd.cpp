// 01-knapsack, randomized, WA
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 101
#define W 100005
int main() {
    int n, w;
    scanf("%d%d", &n, &w);
    pair<int,int> item[N];
    for (int i=0;i<n;i++) scanf("%d", &item[i].first);
    for (int i=0;i<n;i++) scanf("%d", &item[i].second);
    int best=0;
    for (int iter=0; iter<100000; iter++) {
        random_shuffle(item, item+n);
        int profit=0;
        for (int i=0;i<n;i++) {
            if (item[i].first<=w) {
                profit+=item[i].second;
                w-=item[i].first;
            }
        }
        best=max(best, profit);
    }
    printf("%d\n", best);
    return 0;
}
