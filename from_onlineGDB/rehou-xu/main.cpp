#include <iostream>
#include<stack>
using namespace std;
#define siz 1000

int main()
{
    char input;
    int tempI,tempII;
    stack<int> st;
    while(1)
    {
        while(st.size())
        {
            st.pop();
        }
        while(cin>>input)
        {
            if(input<='9'&&input>='0')
            {
                st.push(int(input)-48);
            }
            else
            {
                switch (input)
                {
                    case '+':
                        if(st.size()>1)
                        {
                            tempI=st.top();
                            st.pop();
                            tempII=st.top();
                            st.pop();
                            st.push(tempI+tempII);
                            break;
                        }
                        else
                        {
                            cout<<"輸入錯誤"<<endl;
                            goto end;
                        }
                        break;
                    case '-':
                        if(st.size()>1)
                        {
                            tempI=st.top();
                            st.pop();
                            tempII=st.top();
                            st.pop();
                            st.push(tempI-tempII);
                            break;
                        }
                        else
                        {
                            cout<<"輸入錯誤"<<endl;
                            goto end;
                        }
                        break;
                    case '*':
                        if(st.size()>1)
                        {
                            tempI=st.top();
                            st.pop();
                            tempII=st.top();
                            st.pop();
                            st.push(tempI*tempII);
                            break;
                        }
                        else
                        {
                            cout<<"輸入錯誤"<<endl;
                            goto end;
                        }
                        break;
                    case '/':
                        if(st.size()>1)
                        {
                            tempI=st.top();
                            st.pop();
                            tempII=st.top();
                            st.pop();
                            st.push(tempI/tempII);
                            break;
                        }
                        else
                        {
                            cout<<"輸入錯誤"<<endl;
                            goto end;
                        }
                        break;
                    case '#':
                        if(st.size()==1)
                        {
                            cout<<st.top()<<endl;
                            goto end;
                        }
                        else
                        {
                            cout<<"輸入錯誤"<<endl;
                            goto end;
                            
                        }
                    default :
                    {
                        cout<<"輸入錯誤"<<endl;
                        goto end;
                    }
                }
        
            }
        }
        end:
        {
            cout<<"結束";
        }
    }
    
}

