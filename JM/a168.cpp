#include<iostream>
#include<math.h>

using namespace std;
int main()
{
    float n,input;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>input;
        cout<<int(pow(input,0.5))*10;
    }
} 