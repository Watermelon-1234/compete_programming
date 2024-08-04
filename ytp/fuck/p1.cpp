#pragma GCC optimize("O3,unroll-loops")
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
string N;
int start_index=-1;
int end_index = -1;
#undef int
int main() {
    #define int int64_t
    fastio;
    
    cin>>N;
    if(N=="1")
    {
        cout<<1;
        return 0;
    }
    rep(i,N.length())
    {
        if(N[i]=='1')
        {
            start_index = i+1;
            break;
        }
    }
    if(start_index==-1)
    {
        cout<<"0";
        return 0;
    }
    else if (start_index == N.length())
    {
        start_index--;
        if(N[start_index]=='1')
        {
            cout<<1;
            return 0;
        }   

    }
    for(int i=N.length()-1;i>=start_index;i--)
    {
        // debug(i,int(N[i]));
        
        if(N[i] !=  '0' )
        {
            end_index = i+1;
            break;
        }
    }
    if(end_index==-1 )
    {
        end_index = start_index+1;
    }
    // debug(start_index,end_index);
    bool zero_needed=0;
    for(int i = start_index;i<end_index;i++)
    {
        // safe;
        int output = 9-(int(N[i])-int('0'));

        if(i == end_index-1)
        {
            output+=1;
        }
        if(output!=0)
        {
            zero_needed = 1;
        }
        if(!zero_needed && output==0)
        {
            continue;
        }
        cout<<output;
    }
    for(int i = end_index;i<N.length();i++)
    {
        cout<<0;
    }

    




    return 0;
}