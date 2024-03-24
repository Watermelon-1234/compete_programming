#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,temp=1,sum=0;
    cin>>n>>m;
    for(int i=1;i<n;i++) temp*=i;
    for(int i=n;i<=m;i++)
    {
        temp*=i;
        sum+=temp;
    }
    cout<<sum<<endl;
}