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


int N;
int M;
void move(vector<vector<int>> &array,int &x,int &y,int &s,int d,int n)
{
	//d:
	//1:l->r
	//2:u->d
	//3:r->l
	//4:d->u
	//(x,y):current location(still NULL)
	//s:start_num
	//n:  
	// for(auto i:array)
	// {
	// 	orange(i.begin(),i.end());
	// }
	// debug(x,y,s,d,n);
	if(d%4==1)
	{
		for(int i=0;i<n;i++)
		{
			array[x+i][y]=s+i;
		}
		x+=n;
	}
	if(d%4==2)
	{
		for(int i=0;i<n;i++)
		{
			array[x][y+i]=s+i;
		}
		y+=n;
	}
	if(d%4==3)
	{
		for(int i=0;i<n;i++)
		{
			array[x-i][y]=s+i;
		}
		x-=n;
	}
	if(d%4==0)
	{
		for(int i=0;i<n;i++)
		{
			array[x][y-i]=s+i;
		}
		y-=n;
	}
}

#undef int
int main()
{
	#define int int64_t
    int t;
	cin>>t;
	while(t--)
	{
		int N,M;
		int x=0,y=0;
		int num=1;
		cin>>N>>M;
		//m=2:!counterclockwise
		//m=1:!clockwise	
		vector<vector<int>> array(N,vector<int>(N,0));
		if(M==2)
		{
			for(int j=N-1;j>0;j-=2)
			{
				for(int i=1;i<=4;i++)
				{
					move(array,x,y,num,i,j);
					num+=j;
				}
				x++;y++;
			}
		}
		if(M==1)
		{
			for(int j=N-1;j>0;j-=2)
			{
				for(int i=6;i>=3;i--)
				{
					move(array,x,y,num,i,j);
					num+=j;
				}
				x++;
				y++;
			}
		}
		if(N%2==1)
		{
			array[N/2][N/2]=N*N;
		}
		for(auto i:array)
		{
			for(auto j:i)
			{
				cout<<setw(5)<<j;
			}	
			cout<<endl;
		}
	}
}