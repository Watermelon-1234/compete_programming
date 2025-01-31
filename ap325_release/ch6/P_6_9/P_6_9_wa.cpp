// 01-knapsack, a greedy method, WA
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 101
#define W 100005
bool cmp(pair<int,int> x, pair<int,int> y) {
    return (ll)x.first*y.second <(ll)x.second*y.first;
}
int main() {
    int n, w;
    scanf("%d%d", &n, &w);
    pair<int,int> item[N];
    for (int i=0;i<n;i++) scanf("%d", &item[i].first);
    for (int i=0;i<n;i++) scanf("%d", &item[i].second);
    sort(item, item+n, cmp); // prof/weight larger first
    int profit=0;
    for (int i=0;i<n;i++) {
        if (item[i].first<=w) {
            profit+=item[i].second;
            w-=item[i].first;
        }
    }
    printf("%d\n", profit);
    return 0;
}
