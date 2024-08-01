#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> tail;
    int w=1;
    while(w)
    {
        cout<<"══════════════════════════════════════════════════════════════════════════════════"<<endl;
        cout<<"程式功能選單"<<endl;
        cout<<"1.push"<<endl<<
        "2.pop"<<endl<<
        "3.目前stack元素個數"<<endl<<
        "4.列印全部"<<endl<<
        "5.結束程式"<<endl;
        cout<<"請輸入:";
        int x;
        cin>>x;
        switch (x)
        {
            case 1:
                cout<<"請輸入數字";
                int y;
                cin>>y;
                tail.push(y);
                break;
            case 2:
                if(tail.size()==0)
                {
                    cout<<"現在是空的"<<endl;
                }
                else
                {
                    cout<<"第一個是:"<<tail.top()<<endl;
                    tail.pop();
                }
                break;
            case 3:
                if(tail.size()==0)
                {
                    cout<<"現在是空的"<<endl;
                }
                else
                {
                    cout<<"大小是:"<<tail.size()<<endl;
                }
                break;
            case 4:
                if(tail.size()==0)
                {
                    cout<<"現在是空的"<<endl;
                }
                else
                {
                    stack<int> chen;
                    cout<<"STACK有 ";
                    while(!tail.empty())
                    {
                        chen.push(tail.top());
                        
                        tail.pop();
                    }
                    while(!chen.empty())
                    {
                        tail.push(chen.top());
                        cout<<chen.top()<<" ";
                        chen.pop();
                    }
                    cout<<endl;
                }
                break;
            case 5:
                w=0;
                break;
        }
        cout<<"══════════════════════════════════════════════════════════════════════════════════"<<endl;
    }
}