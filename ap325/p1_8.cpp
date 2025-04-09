/*input
5 17
5 5 8 3 10
*/
// can't pass the last subtask due to TLE the recursive one is in "p1_8_2.cpp"
#include<bits/stdc++.h>
using namespace std;

#define int int64_t

int n,P,sum,dis = __INT64_MAX__;
vector<int> a(50,0);

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> P;
    for(int i = 0;i < n;i++)    
    {
        cin>>a[i];
    }
    for(int i = 0;i <(1<<n);i++)
    {
        int s = 0;
        for(int j = 0;j < n ;j++)
        {
            // cout<<"_j= "<<bitset<8>(1<<j)<<endl;
            if(i & (1<<j))
            {
                // cout<<"j= " << (bitset<8>(j)) <<endl;
                s += a[j];
            }
        }
        if(s > P)
        {
            continue;
        }
        int d = P - s;
        if(d == 0)
        {
            cout<<P;
            return 0;
        }
        if(d < dis)
        {
            dis = d;
            sum = s;
        }
        // cout<<i<<" "<<s<<" "<<bitset<8>(i)<<endl;
    }
    cout<<sum;
}