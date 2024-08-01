#include<iostream>
using namespace std;
int ts(int ti,int t=2)
{
    int sum=1;
    if(t==0)
    {
        return 1;
    }
    if(t==1)
    {
        return t;
    }
    else
    {
        for(int a=1;a<=ti;a++)
        {
            sum*=t;
        }
        return sum;
    }
}
int main()
{
    int a,sum=0,t=0;
    cin>>a;
    while(1)
    {
        if(a==0)
        {
            break;
        }
        else if(a%2==1)
        {
            sum+=ts(t);
        }
        a/=10;
        t++;
    }
    cout<<sum;
}