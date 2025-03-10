// P_3_10 shortest all-color range, unordered_map
#include<bits/stdc++.h>
using namespace std;
#define N 1000010
int seq[N], cnt[N]={0}; // counter of color
unordered_map<int,int> dic; // dictionary

int main() {
    int n;
    scanf("%d",&n);
    // input and discretization
    for (int i=0;i<n;i++) {
        scanf("%d",&seq[i]);
        dic[seq[i]]=0; // insert if not existing
    }
    int n_color=0; // num of color
    for (auto &p:dic) p.second=n_color++;
    // sliding window
    // w_color = num of color in window [left, right-1]
    int left=0, right=0, w_color=0, shortest=n;
    while (right<n) {
        int color=dic[seq[right++]];
        if (++cnt[color]==1) w_color++;
        // shrink left until left color appear only once
        while (1) {
            color=dic[seq[left]];
            if (cnt[color]==1) break;
            cnt[color]--;
            left++;
        }
        if (w_color==n_color)
            shortest=min(shortest, right-left);
    }
    printf("%d\n",shortest);
    return 0;
}

