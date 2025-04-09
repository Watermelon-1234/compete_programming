/*input
3 5 2
*/
#include<bits/stdc++.h>
using namespace std;
#define int int64_t
#define fastio ios::sync_with_stdio(0)
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n"

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

signed main()
{
    fastio;
    cin>>x>>y>>p;
    cout<<exp(y);
}