#include<iostream>
using namespace std;
int main()
{
    while(1)
    {
        int a,b,k,ans=1;
        cout<<"請輸入"<<endl;
        cin>>a>>b>>k;
        for(int i=0;i<b;i++)
        {
            ans=(ans*a)%k;
        }
        cout<<ans<<endl<<endl;
    }
}
