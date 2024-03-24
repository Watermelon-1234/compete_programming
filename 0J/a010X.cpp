#include<iostream>
#include<cmath>
using namespace std;
bool is_prime(long long i)
{
    for(long long j = 2; j <i;j++)
    {
        if(i%j==0) return 0;
    }
    return 1;
}
int main()
{
    unsigned long long i;
    int a[100000]={},k=0;
    cin>>i;
    if(is_prime(i)) 
    {
        cout<<i<<endl;
        return 0;
    }
    int l=i;
    for(auto j = 2; j <l;j++)
    {
        if(is_prime(j))
        {
            while(i%j==0)
            {
                i/=j;
                a[k]+=1;
                //危樑違棟 同志大廈
            }
            k++;
        }
    }
    int h=0;
    k=0;
    for(auto j = 2; j <l;j++)
    {
        if(is_prime(j))
        {
            if(h!=0 || a[k]!=0)
            {
                cout<<" * ";
            }
            if(a[k]==1)
            {
               cout<<j; 
               h++;
            }
            else if(a[k]>1)
            {
                h++;
                cout<<j<<"^"<<a[k];
            }

            k++;

        }
    }
    return 0;
}