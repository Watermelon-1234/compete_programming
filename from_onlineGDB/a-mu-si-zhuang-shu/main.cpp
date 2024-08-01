#include <iostream>
#include<cmath>
using namespace std;
int w(int a)
{
    int t=0;
    while(a)
    {

        a/=10;
        t++;
    }
    return t;
}
int main()
{
    int up,down,sum=0,ever=0;
    cin>>down>>up;
    
    for(int i=down;i<=up;i++)
    {
        int s1=i;
        while(s1)
        {
            
            sum+=pow(s1%10,w(i));
            s1/=10;
        }
        if(i=sum)
        {
            cout<<i<<" ";
            ever=1;
        }
        sum=0;
    }
    if(ever==0)
    {
        cout<<"none";
    }
    
    
    
    
    
    
    return 0;
}
