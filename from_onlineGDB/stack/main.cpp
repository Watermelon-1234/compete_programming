#include <iostream>
using namespace std;
void push (int);
int pop();
void printStack();
struct Stack{
    int s[100];
    int top;
    Stack() 
    {top=-1;}
};
Stack st;
int main(){
    while(1)
    {
        cout<<"1. push 2. pop 3. print stack 4. EXIT"<<endl;
        int input;
        cin>>input;
        if(input==1)
        {
            if(st.top==99)
            {
                cout<<"滿了拉"<<endl;
            }
            else{
                int i;
                cin>>i;
                push(i);
            }
        }
        else if(input==2)
        {
            if(st.top==-1)
            {
                cout<<"沒東西拉"<<endl;
            }
            else
            {
                cout<<pop()<<endl;
            }
        }
        else if(input==3)
        {
            if(st.top==-1)
            {
                cout<<"空的沒得印拉";
            }
            else
            {
                printStack();
            }
        }
        else if(input==4)
        {
            cout<<"do you really want to EXIT?(if yes,type 87)"<<endl;
            int i;
            cin>>i;
            if(i==87)
            {
                break;
            }
            
        }
        else{
            cout<<"could you please use your eyes any brain?"<<endl;
        }
        cout<<"____________________________________________________"<<endl;
    }
    
}
void push(int i)
{
    st.s[++st.top]=i;
}
int pop()
{
    return st.s[st.top--];
}
void printStack()
{
    cout<<"the element in stack:";
    for(int i=0;i<=st.top;i++)
    {
        cout<<st.s[i]<<" ";
    }
    cout<<endl;
}








