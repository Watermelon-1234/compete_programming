// LCS, O(mn) space
#include <bits/stdc++.h>
using namespace std;
#define N 505
int main() {
    char s1[N], s2[N];
    int lcs[N][N];
    scanf("%s%s", s1, s2);
    int n=strlen(s1), m=strlen(s2), i,j;
    for (j=0;j<=n;j++) lcs[0][j]=0;
    for (int i=1; i<=m; i++) {
        lcs[i][0]=0;
        for (int j=1;j<=n;j++)
            if (s2[i-1]==s1[j-1])
                lcs[i][j] = lcs[i-1][j-1]+1;
            else
                lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
    }
    printf("%d\n", lcs[m][n]);
    return 0;
}
