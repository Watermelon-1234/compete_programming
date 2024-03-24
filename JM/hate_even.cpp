#include<iostream>

using namespace std;
int main()
{
    int a;
    cin>>a;
    while(a%2==0)//當A可以整除2就繼續除以2直到不能再除以二
    {
        a/=2;
    }
    cout<<a;
} 