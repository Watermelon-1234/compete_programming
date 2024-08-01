/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;
string a;
string fxxk(string a)
{
    int pare=-1;//不然在下面會偵測錯誤
    for(int i = 0;i<=a.length();i++)
    {
        
        int start_index,end_index;
        if(a[i]=='(')
        {
            if(pare==-1)
            {
                pare=1;//完美避開
                start_index=i;    
            }
            else{
                pare++;
            }
        }
        else if(a[i]==')')
        {
            pare--;
            if(pare==0)
            {
                end_index=i;
                string head,tail;
                head=a;
                tail=a;
                head.erase(start_index,a.length());
                tail.erase(tail.begin,end_index);
                a.erase(a.begin,start_index);
                a.erase(a.begin,end_index-start_index);
                cout<<head<<" "<<a<<" "<<tail<<endl;
                
                //return ;//not yet 
            }
        }
        
    }
    return "fuck";
}
int main()
{
    
    cin>>a;
    cout<<fxxk(a)<<endl;
    return 0;
}
