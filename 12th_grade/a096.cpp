#include<bits/stdc++.h>
using namespace std;
#define int int64_t
#define fastio ios::sync_with_stdio(0)
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n"
#define rep(i,x) for(int i=0;i<x;i++)
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define foo(i,a,b) for(int i=(a);i<(b);i++)
#define oof(i,a,b) for(int i=(a);i>=(b);i--)

pii a[3];
int b[3];
string s1,s2;
bool cmp = false;

signed main()
{
    fastio;
    cin >> s1 >> s2;
    a[0] = mp(10*(s1[0]-'0')+s1[1]-'0',10*(s2[0]-'0')+s2[1]-'0');
    a[1] = mp(10*(s1[3]-'0')+s1[4]-'0',10*(s2[3]-'0')+s2[4]-'0');
    a[2] = mp(10*(s1[6]-'0')+s1[7]-'0',10*(s2[6]-'0')+s2[7]-'0');
    foo(i,0,3)
    {
        b[i] = a[i].S - a[i].F;
    }
    b[0] += 24;
    oof(i,2,0)
    {
        //cout<<b[i]<<" ";
        if(b[i] < 0)
        {
            if(i>0) b[i-1]--;
            b[i] += 60;
        }
    }
    b[0] = b[0]>=24 ? b[0]-24 : b[0];
    foo(i,0,3)
    {
        cout<<setfill('0')<<setw(2)<<b[i];
        if(i!=2) cout<<":";
    }
    cout<<"\0";
    return 0;
}