#pragma GCC optimize("O4,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0);
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n";
#define int int64_t
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define rep(i,n) for(i=0;i<(n);++i)
#define foo(i,a,b) for(i=(a);i<=(b);++i)
#define oof(i,a,b) for(i=(a);i>=(b);--i)
#define all(x) begin(x),end(x)
#define btw(a,b,c) ((a)<=(b)&&(b)<=(c))
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

template <class ...T> void debug(T ...args)
{
    int cnt = sizeof...(T);
    ((cerr << "\e[1;31m"<<"debug: "), ..., (cerr << args << (--cnt ? " " : "\e[0m\n")));
}
template <class T> void orange(T L, T R)
{
    cerr << "\e[1;31m";
    for (int f = 0; L != R; ++L) cerr << (f++ ? " " : "") << *L;
    cerr << "\e[0m\n";
}

template <typename T>
T& inpr()
{
    static T tmp;
    cin>>tmp;
    return tmp;
}

int n,x;

int fast_pow(int base,int times)
{
    if(times == 0)
    {
        return 1;
    }
    else if(times&1)
    {
        return fast_pow(base,time-1) * bast;
    }
    else
    {
        return fast_pow(base,time/2) * fast_pow(base,time/2);
    }
}

void compatible(int f)
{
    int t = sqrt(f);
    if(f == t*t)
    {
        return 1;
    }
    return 0;
}

vector<int> sol(int sum,int cnt,vector<int> history)
{
    
    if(cnt == 4)
    {
        if(compatible(sum))
        {
            history.push_back(sqrt(sum));
        }
    }
    else
    {
        for(int )
    }
}

#undef int
int main()
{
    #define int int64_t
    fastio;
    n = inpr<int>();
    vector<int> ans = sol(fast_pow(2,n),1,vector<int> a());
}