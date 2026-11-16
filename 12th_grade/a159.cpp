#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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


vector<int> col(4),row(4);
int n = 0;
pii error_idx = mp(-1,-1);
bool is_corrupt = 0;

void cleaner()
{
    error_idx = {-1, -1};
    is_corrupt = 0;
    for(auto i:col)
    {
        i = 0;
    }
    for(auto i:row)
    {
        i = 0;
    }
}

#undef int
int main() {
    #define int int64_t
    fastio;
    while (cin >> n)
    {
        cleaner();
        if(!n)
        {
            return 0;
        }
        rep(i, n)
        {
            rep(j, n)
            {
                int tmp = inpr<int>();
                row[i] += tmp;
                col[j] += tmp;
            }
        }
        orange(all(row));
        orange(all(col));
        debug(error_idx.F, error_idx.S);
        rep(i, 4)
        {
            if(row[i] & 1) // odd
            {
                if(error_idx.F == -1)
                {
                    error_idx.F = i;
                }
                else
                {
                    is_corrupt = 1;
                    break;
                }
            }
            if(row[i] & 1) // odd
            {
                if(error_idx.S == -1)
                {
                    error_idx.S == i;
                }
                else
                {
                    is_corrupt = 1;
                    break;
                }
            } 
        }
        if(error_idx.F == -1 && error_idx.S == -1)
        {
            cout << "OK\n";
        }
        else if(is_corrupt || (error_idx.F != error_idx.S && (error_idx.F == -1 || error_idx.S == -1)))
        {
            cout << "Corrupt\n";
        }
        else
        {
            cout<<"Change bit (" << error_idx.F << "," << error_idx.S << ")\n";
        }

    }
    
    
    return 0;
}