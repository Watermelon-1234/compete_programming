/*input
3
1 4 2
5 3 2
7 8 5
*/
#include<bits/stdc++.h>
using namespace std;
#define int int64_t
#define fastio ios::sync_with_stdio(0)
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n"
#define rep(i,x) for(int i = 0;i<x;i++)

int n,sum=0;
vector<int> p(20,-1); // 特判needed
vector<vector<int>> a(20,vector<int> (20,0));

int solve(int s,int t,vector<int> p)
{
    // cout<<"solve"<<endl;
    // safe;
    if(t>=n)
    {
        // safe;
        // cout<<"t>=n"<<endl;
        return s;
    }
    int max = s;
    vector<bool> valid(20,1);
    rep(i,t)
    {
        // safe;
        // cout<<"mdfk"<<endl;
        if(p[i]==-1)
        {
            continue;
        }
        valid[p[i]] = 0;
        int j = p[i] + t-i;
        // cout<<"j="<<j<<endl;
        if(j<n) valid[j] = 0;
        j = p[i] - (t-i);
        if(j<n) valid[j] = 0;
    }
    // for(int i=0;i<n;i++)
    // {
    //     // cout<<"valid["<<i<<"] = "<<valid[i]<<endl;
    // }

    rep(i,n+1)
    {
        if(!valid[i]) continue;
        int best=0;
        if(i>n)
        {
            p[t] = -1;
            // cout<<"choose: a["<<t<<"][-1]"<<endl;
            best = solve(s,t+1,p);
            // cout<<"best: "<<best<<endl;
        }
        else
        {
            // cout<<"choose: a["<<t<<"]["<<i<<"]"<<endl;
            p[t] = i;
            best = solve(s+a[t][i],t+1,p);
            // cout<<"best: "<<best<<endl;
        }
        if(max<best)
        {
            max = best;
        }
    }
    return max;
}

signed main()
{
    fastio;
    // safe;
    cin>>n;
    rep(i,n)
    {
        rep(j,n)
        {
            cin>>a[i][j];
            // cout<<i<<" "<<j<<endl;
            // safe;
        }
    }
    cout<<solve(0,0,p);
}