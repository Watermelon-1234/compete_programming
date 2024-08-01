#include <bits/stdc++.h>

using namespace std;

int t,n,a,b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        vector<int> p(n+1);
        p[0] = 0;
        p[1] = a;
        for(int i = 2;i<=n;i++)
        {
            if(p[i-1]+a<p[i-2]+b)//³æ¶R«K©y
            {
                p[i]=p[i-1]+a;
            }
            else
            {
                p[i]=p[i-2]+b;
            }
        }
        cout<<p[n]<<endl;
    }
}