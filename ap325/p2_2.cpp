/*input
7
0 3 9 3 3 -1 0

*/
#include<bits/stdc++.h>
using namespace std;
#define int int64_t
#define fastio ios::sync_with_stdio(0)
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n"
#define rep(i,x) for(int i=0;i<x;i++)
#define range(x,k) x.begin(),x.begin()+k

const int N = 1e5 + 10;

vector<int> a(N,0),b(N,0);
int n;

int distinct()
{
    vector<int> sorted = a;
    sort(range(sorted,n));
    int t = 1;
    b[0] = sorted[0];
    for(int i = 1;i<n;i++)
    {
        if(sorted[i]!=sorted[i-1])
        {
            b[t] = sorted[i];
            t++;
        }
    }
    return t;
}

signed main()
{
    fastio;
    cin>>n;
    rep(i,n)
    {
        cin>>a[i];
    }
    int distinct_size = distinct();
    rep(i,n-1)
    {
        int tmp = lower_bound(range(b,distinct_size),a[i]) - b.begin();
        cout<<tmp<<" ";
    }
    cout<<lower_bound(range(b,distinct_size),a[n-1])-b.begin();
    
}