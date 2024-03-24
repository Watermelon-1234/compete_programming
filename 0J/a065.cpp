#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    char chr[7];//={'a','b','c','d','e','f','g'};
    for(int i=0; i<7;i++)
    {
        cin>>chr[i];
        if(i==0)
        {
            continue;
        }
        cout<<abs(int(chr[i-1])-int(chr[i]))<<endl;
        //cout<<int(chr[i])<<chr[i]<<endl;
    }
    return 0;
}