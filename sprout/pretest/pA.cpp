#include<bits/stdc++.h>
#define int int64_t
#define F first
#define S second
using namespace std;



int n,q,query;
vector<pair<int,bool>> a;

signed main()
{
    cin>>n>>q;
    for(int i = 0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        a.push_back(make_pair(tmp,0));
    }

    for(int i = 0;i<n;i++)
    {
        bool tmp;
        cin>>tmp;
        if(tmp)
        {
            a[i].S = 1;
        }
    }
    for(int i = 0;i<n;i++)
    {
        int left = i-1,right = i+1;
        if(left>=0)
        {
            if(a[i-1].S)
                a[i].F*=2;
        }
        if(right <n)
        {
            if(a[i+1].S)
                a[i].F*=2;
        }
    }
    while(q--)
    {
        cin >> query;
        query--;
        int left = query-1,right = query+1;
        int ans = a[query].F;
        // cout<<"mid:"<<ans;
        if(left>=0)
        {
            ans += a[left].F;
            // cout<<" / left:"<<ans;
        }
        if(right <n)
        {
            ans += a[right].F;
            // cout<<" / right:";
        }
        cout<<ans<<endl;
    }
}