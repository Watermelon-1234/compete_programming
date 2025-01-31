// P_4_2, one-on-one O(nlogn), sorting+greedy
#include <bits/stdc++.h>
using namespace std;
#define N 100010
int main() {
    int n, enemy[N], ours[N];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&enemy[i]);
    for (int i=0;i<n;i++)
        scanf("%d",&ours[i]);
    sort(enemy, enemy+n); // sort enemy power
    sort(ours, ours+n); // sort our power
    int win=0; // num of win
    for (int i=0,j=0;i<n && j<n;i++) { // for each of our power
        // j is currently weakest enemy
        if (ours[i]> enemy[j]) { // can win some enemy
            win++;
            j++;  // next enemy
        }
        // otherwise, ours[i] is useless
    }
    printf("%d\n",win);
    return 0;
}
