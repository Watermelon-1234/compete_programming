#include<iostream>
using namespace std;

int main()
{
    int price,sum=0;
    while (cin>>price)
    {
        if(price ==-1)
        {
            break;
        }
        else{
            sum += price;//a+=b => a=a+b;
        }
        
    }
    cout<<sum<<endl;
}