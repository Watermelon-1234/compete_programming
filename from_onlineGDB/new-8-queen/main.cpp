#include<iostream>
#include <algorithm>

using namespace std;
int index[8]={},num=0;
void set_get(int row);
int main()
{
    set_get(0);
    cout<<endl;

}
void set_get(int row)
{
    if(row==8)
    {
        cout<<++num<<" ";
        for(int i=0;i<8;i++)
        {
            cout<<index[i]<<"　";
        }
        cout<<endl;
    }
    else
    {
        for(int i=1;i<=8;i++)//放入的數字
        {
            bool t=1;
            for(int j=0;j<row;j++)
            {
                if(i==index[j]||i==index[j]+row-j||i==index[j]-row+j)
                {
                    t=0;
                    break;
                }
            }
            if(t)
            {
                index[row]=i;
                set_get(row+1);
            }
        }
    }


}
