#include <iostream>
#include <limits>
using namespace std;
int n,x;//n面額種數 v[0]面額[1]該面額的張數 x目標
int main()
{
    for(;;)
    {
        cout<<"輸入面額種數 再來輸入面額 再輸入目標金額"<<endl;
        int v[2][100]={};
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>v[0][i];
        }
        cin>>x;
        int coin[x]={0,0};
        for(int i=1;i<x;i++)
        {
            coin[i]=std::numeric_limits<int>::max()-1;//減一是因為如果那格還沒動過要加一的話會overflow
        }
        for(int i=0;i<n;i++)//種類
        {
            for(int j=v[0][i];j<=x;j++)
            {
                if(coin[j]>coin[j-v[0][i]]+1)//小東西比較好
                {
                    coin[j]=coin[j-v[0][i]]+1;
                }
            }
        }
        cout<<coin[x]<<endl;
    }
}