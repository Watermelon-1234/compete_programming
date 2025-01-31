// second algorithm for stepping numbers
// build dp table by top-down method
// find the largest <=N stepping number first
// and then count the number
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define ND 120
LL dp[ND][10];

LL table(int i,int j) {
    int k;
    if (dp[i][j]>=0) return dp[i][j];
    dp[i][j]=0;
    for (k=j;k<10;k++) dp[i][j]+=table(i-1,k);
    return dp[i][j];
}

// find the max stepping number, char is int
int ms(char sn[],int len) {
    int i,j;
    for (i=len-2;i>=0;i--)
        if (sn[i]<sn[i+1]) break;
    if (i<0) return len;
    for (j=i;j>=0;j--) sn[j]=9;
    j=i+1;
    sn[j]--;
    while (j<len && sn[j]<sn[j+1]) {
        sn[j]=9;
        j++;
        sn[j]--;
    }
    while (len>0 && sn[len-1]==0) len--;
    //for (j=len-1;j>=0;j--) printf("%d",sn[j]);printf(":%d\n",len);
    return len;
}

int main() {
	int n,i,j,len,ncase;
	char str[100];

    scanf("%s",str);
    len=strlen(str);//printf("%d:",len);
    for (i=0, j=len-1; i<j; i++, j--)
        swap(str[i],str[j]);
    for (i=0;i<len;i++) str[i]-='0';
    // find the last stepping number
    len=ms(str,len);
    // build table
    len++;
    LL ans=0,t;
    for (j=1;j<10;j++) dp[1][j]=dp[0][j]=1;
    dp[1][0]=dp[0][0]=0;
    for (i=2;i<=len;i++) for (j=0;j<10;j++) dp[i][j]=-1;
    str[len]=0;
    t=table(len,0);

    for (i=len-2;i>=0;i--) {
        for (j=str[i+1];j<str[i];j++)
            ans+=dp[i+1][j];
    }
    ans++;
    printf("%lld\n",ans);
	return 0;
}
