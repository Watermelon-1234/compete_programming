/*input
3 5 2
*/
#include<bits/stdc++.h>
using namespace std;
#define int int64_t
#define fastio ios::sync_with_stdio(0)
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n"
#define rep(i,x) for(int i=0;i<x;i++)
string s;
int x,y,p;
int exp(int b)
{
    if(!b)
    {
        return 1;
    }
    if(b & 1)
    {
        return exp(b-1)*x%p;
    }
    int t = exp(b/2);
    return (t*t)%p;
}

int mod(string a)
{
    int len = a.length(),sum = 0;
    rep(i,len)
    {
        int tmp = int(a[i]-'0');
        // cout<<tmp<<endl;
        sum = (sum*10+tmp)%p;
    }
    return sum;
}

signed main()
{
    fastio;
    cin>>s>>y>>p;
    x = mod(s);
    cout<<exp(y);
}