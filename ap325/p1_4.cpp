/*input
7 3
2 4 1 3 7 6 9
*/

#include<bits/stdc++.h>
using namespace std;

#define int int64_t
int N,K;
vector<int> p(50010,0);

int cost(int left,int right,int layer)
{
    cout<<left<<"/"<<right<<"/"<<layer<<endl;
    if(layer>K || right - left <=2) // a segment without cutpoint is no need to cut
    {
        return 0;
    }
    int min = INT64_MAX,sum=0,m;
    cout<<sum<<endl<<endl;
    for(int j = left+1,sum = 0;j < right;j++)
    {
        for(int i = left;i<=right;i++)
        {
            sum += abs(j-m)*p[i];
            cout<<p[i];
            // cout<<"j/i = "<<j<<"/"<<i<<endl;
            // cout<<"sum is now:"<<sum<<endl;
        }
        cout<<"sum: "<<sum<<endl;
        if(sum < min)
        {
            min = sum;
            m = j;
        }
        else if(sum == min)
        {
            m = m<j ? m : j;
        }
    }

    return p[m] + cost(left,m,layer+1) + cost(m,right,layer+1);
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