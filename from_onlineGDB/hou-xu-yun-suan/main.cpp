#include <iostream>
#include<stack>
using namespace std;
#define siz 1000

int main()
{
    char input;
    int tempI,tempII,ans;
    stack<int> st;
    for(int i = 0;i<siz;i++)
    {
        if(input[i]>='0'&&input[i]<='9')
        {
            st.push(int(input[i])-48);
            cout<<int(input[i])-48;
        }
        else
        {
            switch (input[i])
            {
                case '+':
                    if(st.size()>1)
                    {
                        tempI=st.top();
                        st.pop();
                        tempII=st.top();
                        st.pop();
                        st.push(tempI+tempII);
                    }
                    else
                    {
                        cout<<"輸入錯誤"<<endl;
                        break;
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
                    }
                    else
                    {
                        cout<<"輸入錯誤"<<endl;
                        break;
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
                    }
                    else
                    {
                        cout<<"輸入錯誤"<<endl;
                        break;
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
                        
                    }
                    else
                    {
                        cout<<"輸入錯誤"<<endl;
                        break;
                    }
                    break;
                default :
                {
                    cout<<"輸入錯誤"<<endl;
                    break;
                }
            }
    
        }
    }
    if(st.size()!=0)
    {
        cout<<"輸入錯誤"<<endl;
    }
    else{
        cout<<"結果"<<ans<<endl;
    }
}
