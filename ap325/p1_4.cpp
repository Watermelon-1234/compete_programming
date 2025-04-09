/*input
5 1
1 2 3 4 100
*/

#include<bits/stdc++.h>
using namespace std;

#define int int64_t
int N,K;
vector<int> p(50010,0);

int cost(int left,int right,int layer)
{
    // cout<<left<<"/"<<right<<"/"<<layer<<endl;
    if(layer>K || right - left <=2) // a segment without cutpoint is no need to cut
    {
        return 0;
    }
    int min = INT64_MAX,sum=0,m;
    // cout<<sum<<endl<<endl;
    for(int j = left+1;j < right;j++,sum = 0)
    {
        for(int i = left;i<=right;i++)
        {
            sum += abs(j-i)*p[i];
            // cout<<p[i]<<endl;
            // cout<<"j/i = "<<j<<"/"<<i<<endl;
            // cout<<"sum is now:"<<sum<<endl;
        }
        // cout<<"___________________________"<<endl;
        // cout<<"sum: "<<sum<<endl;
        if(sum < min)
        {
            min = sum;
            m = j;
        }
        // else if(sum == min)
        // {
        //     m = ;
        // }
        // cout<<"m_="<<m<<endl;
    }
    // cout<<"m="<<m<<endl;
    return p[m] + cost(left,m-1,layer+1) + cost(m+1,right,layer+1);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i = 0;i<N;i++)
    {
        int t;
        cin>>t;
        p[i] = t;
    }
    // for(auto i:p)
    // {

    // }
    cout << cost(0,N-1,1); // [0,N-1]
}