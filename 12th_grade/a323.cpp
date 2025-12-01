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

vector<int> a;
string s;
int input, i = 1, pre = 0, same;
bool inc = 1,printed = 1, same_at_start = 0;

#undef int
int main() {
    #define int int64_t
    fastio;
    getline(cin, s);

    stringstream ss;

    ss << s;



    while(ss >> input) 
    {
        if(input < pre)
        {
            // debug(i, input ,pre,inc);
            if(inc == 1 && i != 2) 
            {
                if(same) 
                {
                    if (same_at_start)
                    {
                        same = 0;
                        same_at_start = 0;
                        break;
                    }
                    cout<<same<<" ";
                    same = 0;
                }
                cout<<i-1<<" "<<pre<<endl;
                inc = 0;
                printed = 0;
            }
            same = 0;
        }
        else if(input ==pre)
        {
            if(!same) 
            {
                same = i-1;
            }
            if(i <= 2) 
            {
                same_at_start = 1;
            }
        }
        else
        {
            inc = 1;
            same = 0;
        }

        i++;
        pre = input;
        
    }
    ss.clear();
    ss.str("");
    if(printed)
    {
        cout<<"0 0"<<endl;
    }
    return 0;
}