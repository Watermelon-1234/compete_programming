#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=1;
    char input;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input;
        if(input-'+')//-
        {
            sum*=-1;
        }
    }
    if(sum+1)
    {
        cout<<"+";
    }
    else
        cout<<"-";
}