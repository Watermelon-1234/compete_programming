#include <iostream>
using namespace std;
int main()
{
    unsigned long long m,input,expected,sum=0;
    cin>>m;
    for(int i=0;i<m-1;i++)
    {
        cin>>input;
        sum+=input;
    }
    expected=m*(m+1)/2;
    cout<<expected-sum;
}