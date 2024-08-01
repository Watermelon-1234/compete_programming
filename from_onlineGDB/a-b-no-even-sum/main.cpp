#include <iostream>
using namespace std;
int isb(int a)
{
    if(a%2==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    
    int mi=0,ma=0,i=0,is=0;
    long int sum=0;
    cin>>mi>>ma;
    i=mi;
    while(i>=mi&&i<=ma)
    {
        is=isb(i);
        if(is==1)
        {
            sum+=i;
        }
        i++;
    }
    cout << sum << endl;
}
