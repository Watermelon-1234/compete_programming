#include<bits/stdc++.h>
using namespace std;
int main()
{
    bool v[2][7]={};
    bool is_allpass = true;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j <7;j++)
        {
            cin>>v[i][j];
        }
    }
    for(int i = 0; i < 2; i++)
    {
        if(v[i][1]==v[i][3]||v[i][1]!=v[i][5])
        {
            cout<<"A";
            is_allpass = false;
            break;
        }
    }
    if(v[0][7-1]==1&&v[1][7-1]==0)
    {

    }
    else{
        cout<<"B";
        is_allpass = false;
    }
    for(int i=1;i<=5;i+=2)
    {
        if(v[0][i]==v[1][i])
        {
            cout<<"C";
            is_allpass = false;
            break;
        }  
    }
    if(is_allpass)
    {
        cout<<"None";
    }
}
