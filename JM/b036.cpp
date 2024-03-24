#include<iostream>

using namespace std;
int main()
{
    int n,input,count=0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input;
        if(input>=80)
        {
            count++;
        }
    }
    cout<<count;
} 