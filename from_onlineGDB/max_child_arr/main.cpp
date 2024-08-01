#include<iostream>
#define size 10
using namespace std;

int main()
{
    int max=0,arr[size]={};
    for(int i = 0;i<size;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<size;i++)
    {
        for(int k=0;k<size-i;k++)
        {
            int sum=0;
            for(int j=i;j<i+k;j++)
            {
                sum+=arr[j];
            }
            if(sum>=max)
            {
                max=sum;
            }
        }
    }
    cout<<max;
}