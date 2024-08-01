#include<bits/stdc++.h>

using namespace std;
int main()
{
    int max=1,current=1;
    char a,previous='\0';
    while(cin>>a)
    {
        
        if(a==previous)
        {
            current++;
        }
        else
        {
            current=1;
        }
        if(current>max)
        {
            max=current;
        }
        previous=a;
    }

    cout<<max;
}