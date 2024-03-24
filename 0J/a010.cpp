#include<iostream>
using namespace std;
int main()
{
    int a=2,b;
    cin>>b;
    while(b>=a)
    {
        if(b%a==0)
        {
            int n=0;
            while(b%a==0)
            {
                b/=a;
                n++;
            }
            n>1 ? cout<<a<<"^"<<n : cout<<a;
            if(b==1) return 0;
            else cout<<" * ";


        }
        a++;
    }
}