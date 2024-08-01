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


vector<pair<int,int>> n;
set<int> n_length;
vector<pair<int,int>> d;
set<int> d_length;


int q;

void print_array(vector<pair<int,int>> array)
{
    cerr << "\n\e[1;31m"<<"print array: \n";
    int idx=0;
    for(int i=0;i<array.size();i++)
    {
        cerr<<idx<<" first: "<<array[i].F<<" second: "<<array[i].S<<endl;
        idx++;
    }
    cerr<<"\e[0m\n";
}

int make_distance(int x1,int x2,int y1,int y2)
{
    return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void calculate_length(vector<pair<int,int>> points,set<int> &lengths)
{
    for(int i=0;i<3;i++)
    {
        int distance = make_distance(points[i].F,points[(i+1)%3].F,points[i].S,points[(i+1)%3].S);
        // debug(i,distance);
        // print_array(points);
        lengths.insert(distance);
    }
}

#undef int
int main() {
    #define int int64_t
    fastio;
    int i=3;
    while(i--)
    {
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        n.push_back(mp(tmp1,tmp2));
    }
    calculate_length(n,n_length);
    // orange(n_length.begin(),n_length.end());
    i=3;
    while(i--)
    {
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        d.push_back(mp(tmp1,tmp2));
    }
    calculate_length(d,d_length);
    // orange(d_length.begin(),d_length.end());
    cin>>q;
    while(q--)
    {
        vector<pair<int,int>> input;
        set<int> input_length;
        i=3;
        while(i--)
        {
            int tmp1,tmp2;
            cin>>tmp1>>tmp2;
            input.push_back(mp(tmp1,tmp2));
        }
        calculate_length(input,input_length);
        // orange(input_length.begin(),input_length.end());
        if(input_length==n_length)
        {
            cout<<"Nijika\n";
        }
        else if(input_length==d_length)
        {
            cout<<"Doritos\n";
        }
        else
        {
            cout<<"None\n";
        }
    }
    
    return 0;
}
