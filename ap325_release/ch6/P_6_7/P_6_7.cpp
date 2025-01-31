// LCS, linear space
#include <bits/stdc++.h>
using namespace std;
#define N 505
int main() {
    char s1[N], s2[N];
    scanf("%s%s", s1, s2);
    int n=strlen(s1), m=strlen(s2);
    int lcs[2][N]={0}, from=0, to=1;
    for (int i=0; i<m; i++) {
        for (int j=1;j<=n;j++)
            lcs[to][j] = (s2[i]==s1[j-1])? lcs[from][j-1]+1: \
                max(lcs[to][j-1], lcs[from][j]);
        swap(from, to); // int temp=from; from=to; to=temp;
    }
    printf("%d\n", lcs[from][n]); // final result at [from]
    return 0;
}
