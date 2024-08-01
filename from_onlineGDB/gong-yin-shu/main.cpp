#include<iostream>
using namespace std;
int imp[100];//因數1
int imp2[100];
int d=0;
void bec(int a)//搞因數
{
    int b;
    for(b=1;b<=a;b++)
    {
        if(a%b==0)
        {
            imp[d]=b;
            d++;
        }
    }
}

void bec1(int a)//搞因數
{
    int b;
    d=0;
    for(b=1;b<=a;b++)
    {
        if(a%b==0)
        {
            imp2[d]=b;
            d++;
        }
    }
}
int main()
{
    int a,b,c[100];
    cin>>a;
    bec(a);
    cin>>b;
    bec1(b);
    for(b=0;b<=100;b++)//輸出
    {
        for(a=0;a<=100;a++)//輸出
        {
            if(imp[b]==imp2[a])
            {
                if(imp[b]!=0)
                {
                    cout<<imp[b]<<" ";
                }
                
            }
        
        }  
        
    }
}




