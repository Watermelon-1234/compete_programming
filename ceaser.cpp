#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    
    cin>>a;
    for(int i=-26;i<26;i++)
    {
        for(auto j=0;j<a.length();j++)
        {
            cout<<char(a[j]+i);
        }
        cout<<endl;   
    }
}