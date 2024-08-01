#include <iostream>
#include<stack> 
#include<string>
using namespace std;
int main()
{
    cout<<"請輸入:....."<<endl;
    char input[1000]={};
    int _big=0,_mid=0,_small=0;
    stack<int> big,medium,small;
    cin>>input;
    for(int i=0;i<=1000;i++)
    {
        if(input[i]=='{')
        {
           
           if(medium.size()!=0||small.size()!=0)
            {
               cout<<"炸了拉";
               exit(0);
            }
            _big++; 
            big.push(1); 
        } 
        else if(input[i]=='[')
        {
           if(small.size()!=0)
           {
               cout<<"炸了拉";
               exit(0);
           }
           _mid++; 
           medium.push(1); 
        }
        else if(input[i]=='(')
        {
           _small++; 
           small.push(1); 
        }
        else if(input[i]=='}')
        {
           big.pop(); 
        } 
        else if(input[i]==']')
        {
           medium.pop(); 
        }
        else if(input[i]==')')
        {
           small.pop(); 
        }
        else
        {
            break;
        }
        
    }
    if(big.size()==0&&medium.size()==0&&small.size()==0)
    {
        cout<<"成功"<<endl;
        cout<<"big= "<<_big<<" small= "<<_small<<" medium= "<<_mid<<endl;
    }
    else
    {
        cout<<"炸了拉";
    }
    return 0;
}
