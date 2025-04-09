/*input
6 7
1 1 1 0 1 1 0
1 1 1 1 1 1 0
1 1 0 1 1 0 1
1 1 1 0 1 1 0
1 1 1 0 1 1 0
1 1 0 1 1 1 0

*/
#include<bits/stdc++.h>
using namespace std;
#define int int64_t
#define fastio ios::sync_with_stdio(0)
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n"
#define F first
#define S second
#define rep(i,x) for(int i=0;i<x;i++)

int m,n;
vector<vector<int>> a(13,vector<int>(13,0));
int depth = 0;

int cost(pair<int,int> r1,pair<int,int> r2)
{
    // cout<<"_r1 = ("<<r1.F<<","<<r1.S<<")"<<endl;
    // cout<<"_r2 = ("<<r2.F<<","<<r2.S<<")"<<endl;
    int c = 0;
    int d = max(r2.F-r1.F,r2.S-r1.S) + 1;
    for(auto i = r1.F;i<=r2.F;i++)
    {
        for(auto j = r1.S;j<=r2.S;j++)
        {
            // cout<<"*p = ("<<i<<","<<j<<") = "<<a[i][j]<<endl;
            c+=a[i][j];
        }
    }
    // cout<<"c = "<<c<<endl;
    // cout<<"c' = "<<d-c<<endl;
    return min(c,d-c);
}

int solve(int sum,pair<int,int> r1,pair<int,int> r2,string test)
{
    // cout<<"r1 = ("<<r1.F<<","<<r1.S<<")"<<endl;
    // cout<<"r2 = ("<<r2.F<<","<<r2.S<<")"<<endl;
    // depth++;
    // cerr << string(depth, '.') << "ENTER solve with r1=(" << r1.F << "," << r1.S << "), r2=(" << r2.F << "," << r2.S << "), sum=" << sum << " test=" << test <<endl;
    if(r1.F == r2.F || r1.S == r2.S)
    {   
        // if(sum<6)
        //     cout<<sum<<""<<test<<endl;
        return sum;
    }
    pair<int,int> up_right(r1.F,r2.S),down_left(r2.F,r1.S);
    // depth--;
    int result = min({
        solve(sum + cost(r1,up_right),make_pair(r1.F+1,r1.S),r2,test+"u"),
        solve(sum + cost(r1,down_left),make_pair(r1.F,r1.S+1),r2,test+"l"),
        solve(sum + cost(down_left,r2),r1,make_pair(r2.F-1,r2.S),test+"d"),
        solve(sum + cost(up_right,r2),r1,make_pair(r2.F,r2.S-1),test+"r")
    });

    return result;
    // return sum;
}

signed main()
{
    fastio;
    cin>>m>>n;
    rep(i,m)
    {
        rep(j,n)
        {
            cin>>a[i][j];
        }
    }
    cout<<solve(0,make_pair(0,0),make_pair(m-1,n-1),"");

}