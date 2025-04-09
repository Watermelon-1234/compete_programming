/*input
5 17
5 5 8 3 10
*/
#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define int int64_t

int n,P;
vector<int> a(50,0);

int solve(int s,int t)
{
    int s1 = -1,s2 = -1;
    if(t>=n)
    {
        return s;
    }
    if(s+a[t]<P)
    {
        s1 = solve(s+a[t],t+1);
    }
    s2 = solve(s,t+1);
    return max(s1,s2);
}

signed main()
{
    fastio;
    cin >> n >> P;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    cout << solve(0,0);

}