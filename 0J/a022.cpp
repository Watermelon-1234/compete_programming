#include<iostream>
#include<string>
using namespace std;
int main()
{
    string chr;
    int r=0;//最後一個字元的index
    cin>>chr;
    r=chr.length()-1;
    for(int i=0;i<r/2;i++)
    {
        if(chr[i]!=chr[r-i])
        {
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes";
}