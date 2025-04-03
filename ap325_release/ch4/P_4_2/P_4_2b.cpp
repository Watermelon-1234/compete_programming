// P_4_2b, using PQ
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n , k, win=0;
    scanf("%d",&n);
    priority_queue<int> enemy,ours;
    for (int i=0;i<n;i++) {
        scanf("%d",&k);
        enemy.push(k);
    }
    for (int i=0;i<n;i++) {
        scanf("%d",&k);
        ours.push(k);
    }
    // max on the top
    while (!ours.empty()) {
        // find the largest I can win
        while (!enemy.empty() && enemy.top()>=ours.top())
            enemy.pop();
        if (enemy.empty()) break; // win no one
        win++;
        enemy.pop();
        ours.pop();
    }
    printf("%d\n",win);
    return 0;
}
