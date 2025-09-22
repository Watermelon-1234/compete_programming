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
#define foo(i,a,b) for(int i=(a);i<(b);i++)
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

int worst_case = -1,best_case = 101,input,N;
vector<int> a;

#undef int
int main() {
    #define int int64_t
    fastio;
    N = inpr<int>();
    foo(i,0,N)
    {
        input = inpr<int>();
        a.push_back(input);

        if(input >= 60 && input < best_case)
        {
            best_case = input;
        }
        else if(input < 60 && input > worst_case)
        {
            worst_case = input;
        }

    }
    // cout << (worst_case == -1 ? "best case\n" : worst_case);
    // cout << (best_case == 101 ? "worst case\n" : worst_case);
    sort(all(a));
    for(auto i:a)
    {
        cout<<i<<" ";   
    }
    cout<<"\n";
    if(worst_case == -1)
    {
        cout<<"best case\n";
    }
    else
    {
        cout<<worst_case<<endl;
    }
    if(best_case == 101)
    {
        cout<<"worst case\n";
    }
    else
    {
        cout<<best_case<<endl;
    }

    return 0;
}