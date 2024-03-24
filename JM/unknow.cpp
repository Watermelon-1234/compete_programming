#include<bits/stdc++.h>
using namespace std;

int main()
{
    float m,n,k;
    cin>>m>>n;
    k=(m+n)/2;
    if(k>60||k==60)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}