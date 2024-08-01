#include<iostream>
using namespace std;
int main()
{
    int a=1,b=1,tp;
    for(a=1;a<=1000;a++)
    {
        for(b=1;b<=1000;b++)
        {
            tp=a*b;
            cout<<a<<"X"<<b<<"="<<tp<<" ";
        }
        cout<<endl;
    }
}