#include<bits/stdc++.h>
using namespace std;
int main()
{
    pair<int ,int > range;
    int v,p;
    cin>>range.first>>range.second>>v>>p;
    if(range.first>range.second)
    {
        swap(range.first,range.second);
    }
    if(v==range.first||v==range.second)
    {
        cout<<-2*p;
        return 0;
    }
    else if(v>range.first&&v<range.second)
    {
        cout<<2*p;
        return 0;
    }
    else{
        cout<<-1*p;
        return 0;
    }

}