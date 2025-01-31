// P_3_10 shortest all-color range,
// for checking ans. using binary search to find shortest
#include<bits/stdc++.h>
using namespace std;
#define N 1000010
int seq[N];
int dic[N]; // dictionary, map color to 0~m-1
// max num of color of window size w
int w_col(int w) {
    vector<int> cnt(n, 0);
    if (color<=dic[0]) return 0;
    int p=0;
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
        seq[i]=lower_bound(dic,dic+n_color,seq[i]);
    // end of discretization
    if (n_color==1) {printf("1\n"); return 0;}
    // using binary search to find the longest invalid length
    int length=1;
    for (int jump=n/2; jump>0; jump>>=1) {
        while (w_col(length+jump)<n_color)
            length+=jump;
    }
    printf("%d\n",length);
    return 0;
}

