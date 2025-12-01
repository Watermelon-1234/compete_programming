#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0)
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n"
#define int int64_t
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define rep(i,n) for(int i=0;i<(n);++i)
#define foo(i,a,b) for(int i=(a);i<=(b);++i)
#define oof(i,a,b) for(int i=(a);i>=(b);--i)
#define all(x) begin(x),end(x)
#define btw(a,b,c) ((a)<=(b)&&(b)<=(c))
using namespace std;

// Variadic debug function with variable name printing
template <typename T>
void print_debug(const char* name, T value) {
    cerr << "\e[1;31m" << name << " = " << value;
}

template <typename T, typename... Args>
void print_debug(const char* names, T value, Args... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " = " << value;
    if (comma) cerr << ", ";
    print_debug(comma + 1, args...);
}

template <typename T, typename... Args>
void formatter(const char* names, T value, Args... args) {
    cerr << "\e[1;31m"<< "debug: [" ;
    print_debug(names,value, args...);
    cerr <<  "]"  << "\e[0m\n";
}

#define debug(...) formatter(#__VA_ARGS__, __VA_ARGS__)

// Orange function for range printing
template <typename T>
void orange(T L, T R) {
    cerr << "\e[1;31morange: ";
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


int n,k,sq,tmp,upr_bound,lwr_bound;

#undef int
int main() {
    #define int int64_t
    fastio;
    cin>>n;
    while(n--)
    {
        int k = inpr<int>();
        upr_bound = sqrt(pow(10,(k)));
        lwr_bound = sqrt(pow(10,(k-1)));
        for(int i = ((lwr_bound & 1) ? lwr_bound+1 : lwr_bound);i<=upr_bound;i+=2)
        {
            sq = i*i;
            int tmp = sq;
            // debug(i,sq);
            while(tmp>0)
            {
                // debug(tmp);
                if ((tmp%10)%2==0)
                {
                    tmp/=10;
                }
                else
                {
                    break;
                }
            }
            if(!tmp)
            {
                cout<<sq<<endl;
                break;
            }
 
        }
    }

    
    
    return 0;
}