#pragma GCC optimize("O4,unroll-loops")
#include <bits/stdc++.h>
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
using namespace std;

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
bool solved = 0;

int fast_pow(int base,int times)
{
    if(times == 0)
    {
        return 1;
    }
    else if(times&1)
    {
        return fast_pow(base,times-1) * base;
    }
    else
    {
        return fast_pow(base,times/2) * fast_pow(base,times/2);
    }
}

// void compatible(int f)
// {
//     int t = sqrt(f);
//     if(f == t*t)
//     {
//         return 1;
//     }
//     return 0;
// }

void sol(int sum,int cnt,int pick,vector<int> history)
{
    sum -= pick * pick;
    // debug(sum,cnt,pick);
    if(cnt == 4)
    {
        // safe;
        if(sum == 0)
        {
            solved = 1;
            for(auto i:history)
            {
                cout<<i<<" ";
            }
            cout<<'\n';
        }
    }
    else if(sum > 0)
    {
        if(sum < pick * pick)
        {
            return;
        }
        // safe;
        for(int i = pick; i <= sqrt(sum); i++)
        {
            history.push_back(i);
            sol(sum, cnt + 1, i, history);
        }
    }
}

#undef int
int main()
{
    #define int int64_t
    fastio;
    n = inpr<int>();
    for(int i = 1;i < fast_pow(2,(n%2?n:n+1)/2);i++)
    {
        vector<int> a;
        a.push_back(i);
        sol(fast_pow(2,n),1,i,a);
    }
    if(!solved)
    {
        cout<<0<<"\n";
    }
}