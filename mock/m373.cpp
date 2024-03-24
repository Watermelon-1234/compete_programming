#include<bits/stdc++.h>
// dp[k,n] max subarray end at n and with at most k masked
// dp[0,n] = max(dp[0,n-1],0) + v[i]
// dp[k,n] = max(dp[k-1,n-1], dp[k,n-1]+v[i]) for k>0
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    vector<int> dp(n,k);
    
}