#include <iostream>
using namespace std;
int main()
{
    int x,y,a[2],b[2],s[2],max,min;
    while(1)
    {
        cout<<"請輸入最大臨界值(輸入9999為預設"<<endl;
        cin>>max;
        cout<<"請輸入最小臨界值(輸入-9999為預設"<<endl;
        cin>>min;
        cout<<"請輸入X的係數1"<<endl;
        cin>>a[1];
        cout<<"請輸入Y的係數1"<<endl;
        cin>>b[1];
        cout<<"請輸入常數(等於多少1"<<endl;
        cin>>s[1];
        cout<<"請輸入X的係數2"<<endl;
        cin>>a[2];
        cout<<"請輸入Y的係數2"<<endl;
        cin>>b[2];
        cout<<"請輸入常數(等於多少2"<<endl;
        cin>>s[2];
        for(x=min;x<=max;x++)
        {
            for(y=min;y<=max;y++)
            {
                if((x*a[1]+y*b[1]==s[1])&&(x*a[2]+y*b[2]==s[2]))
                {
                    cout<<"x="<<x<<endl<<"y="<<y<<endl<<"--------------------------------"<<endl;
                    break;
                }
                else
                {
                    if(x==max&&y==min)
                    {
                        cout<<"我找不出來(打我啊!?"<<endl<<"--------------------------------"<<endl;
                        
                    }
                }
            }
        }
    }
}   

