#include<bits/stdc++.h>
#define int int64_t
#define F first
#define S second
using namespace std;


int M,N,K,input,max = 0;
vector<int> ans(1e9+1,make_pair(0,1));//a: <填的格,畫那一格> ans:該號碼被畫過幾次
vector<pair<int,int>> a(1e6+1,0);

signed main()
{
    cin>>N>>M>>K;
    for(int i = 0;i<N;i++)
    {
        cin>>input;
        a[i] = input;
        ans[input]++;
        if(ans[input]>max)
            max = ans[input];
    }
    if(max>K)
    {
        cout<< -1 ;
        return 0;
    }
    

}