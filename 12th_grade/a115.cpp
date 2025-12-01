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

vector<pair<pii,int>> a(50,{{-1,-1},0});
vector<int> column(10, 0), row(10, 0), diag(2, 0);
int input, max_score = -1, best_pos = -1; // max score一定要小於-1


#undef int
int main() {
    #define int int64_t
    fastio;

    // 先把賓果號碼做映射 a[x]={column, row}
    rep(i, 5)
    {
        rep(j, 5)
        {
            int x = inpr<int>();
            a[x].F = {i, j};
        }
    }
    // for(auto &x:a)
    // {
    //     debug(x.F.F, x.F.S);
    //     debug(x.S);
    // }
    // 紀錄行 列 對角 缺幾格連線
    while(cin>>input)
    {
        if(input == -1)
        {
            break;
        }
        if(a[input].S==1)
        {
            continue;
        }
        column[a[input].F.F]+=1;
        row[a[input].F.S]+=1;
        a[input].S=1;
        if(a[input].F.F == a[input].F.S)
        {
            diag[0]+=1;  // tan theta = -1
        }
        if(a[input].F.F + a[input].F.S == 4)
        {
            diag[1]+=1;  // tan theta = 1
        }
    }

    // orange(all(column));
    // orange(all(row));
    // orange(all(diag));

    // for(auto x:a)
    // {
    //     debug(x.F.F, x.F.S);
    //     debug(x.S);
    // }

    // 比較算分

    foo(i,1,25)
    {
        int score = 0;
        if(a[i].S == 0)
        {
            if(column[a[i].F.F] +1 == 5)
            {
                score += 1;
                // cout<<"col";
            }
            if(row[a[i].F.S] + 1== 5)
            {
                score += 1;
                // cout<<"row";
            }
            
            if(a[i].F.F == a[i].F.S && diag[0] + 1==5 )
            {
                score += 1;
                // cout<<"diag0";
            }
            if(a[i].F.F + a[i].F.S == 4 && diag[1] +1 ==5)
            {
                score += 1;
                // cout<<"diag1";
            }
            debug(i,a[i].F.F,a[i].F.S, score);
        }
        else
        {
            continue; // it is necessary because the already marked number may somehow give a higher score
        }
        if(score > max_score)
        {
            max_score = score;
            best_pos = i;
        }
    }
    debug(max_score);
    cout << best_pos;

    return 0;
}
/*
1 9 23 17 18
10 24 8 16 2
11 13 3 7 19
12 4 15 6 20
25 14 5 22 21
1
17
24
8
16
2
11
3
7
12
25
22
21
-1
*/
