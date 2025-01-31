// P_3_10 shortest all-color range, only basic instruction
#include<bits/stdc++.h>
using namespace std;
#define N 1000010
int seq[N], cnt[N]={0}; // counter of color
int dic[N]; // dictionary, map color to 0~m-1
// binary search to find id of color
int c_id(int color, int nc) {
    if (color<=dic[0]) return 0;
    int p=0;
    for (int jump=nc/2; jump>0; jump>>=1) {
        while (p+jump<nc && dic[p+jump]<color)
            p+=jump;
    }
    return p+1;
}

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&seq[i]);
    // discretization
    for (int i=0;i<n;i++)
        dic[i]=seq[i];
    sort(dic, dic+n);
    // remove duplicate color
    int n_color=1; // num of color
    for (int i=1;i<n;i++) { // not checking dic[0]
        if (dic[i]!=dic[i-1]) {
            dic[n_color]=dic[i];
            n_color++;
        }
    }
    // replace color with its rank
    for (int i=0;i<n;i++)
        seq[i]=c_id(seq[i],n_color);
    // end of discretization, start sliding window
    // w_color = num of color in window [left, right-1]
    int left=0, right=0, w_color=0, shortest=n;
    while (right<n) {
        cnt[seq[right]]++;
        if (cnt[seq[right]]==1) w_color++;
        right++;
        // shrink left until left color appear only once
        while (cnt[seq[left]]>1) {
            cnt[seq[left]]--;
            left++;
        }
        if (w_color==n_color)
            shortest=min(shortest, right-left);
    }
    printf("%d\n",shortest);
    return 0;
}

