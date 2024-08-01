#include<iostream>
using namespace std;
int imp[1000];//因數
int bmp1[1000];
int bmp2[1000];
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
    }//函數傳陣列
}
void bbec(int c,int e)
{
    int b;
    bec(c);
    for(b=0;b<=d;b++)
    {
        bmp1[b]=imp[b];
    }
    bec(e);
    for(b=0;b<=d;b++)
    {
        bmp2[b]=imp[b];
    }
    for(b=0;b<=d;b++)//輸出
    {
        for(c=0;c<=d;c++)
        {
            if(imp[b]==0)
            {
                break;
            }
            cout<<imp[b]<<" ";
        }
    }
}
int main()
{
    int a,b;
    cin>>a>>b;
    

}














































