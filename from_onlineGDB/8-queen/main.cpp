#include<iostream>

using namespace std;

void queen(int);
int arr[8][8]={},count=0;
int main()
{
    queen(0);
}
void queen(int row)
{
    if(row==8)
    {
        count++;
        cout<<cout<<" ";
        for(int i=0;i<8;i++)
        {
            for(int j=0;k<8;j++)
            {
                if(arr[i][j]==1)
                {
                    cout<<j<<" ";
                }
            }
        }
        cout<<endl;
    }
    else
    {
        for(int i=row;i<8;i++)
        {
            for(int j=0;k<8;j++)
            {
                if(arr[i][j]!=-1)
                {
                    bool success=TRUE;
                    for(int k=0;k<8;k++)
                    {
                        if(arr[j][k]==1)
                        {
                            success=FALSE;
                        }
                    }
                    for(int k=0;k<8;k++)
                    {
                        for(int l=j-i;l<8;l++)
                        {
                            if(k<0||l<0)
                            {
                                continue;
                            }
                            else if(k>8||l>8)
                            {
                                break;
                            }
                        }
                    }
                    
                    
                    if(success)
                    {
                        for(int l=0;l<8;l++)
                        {
                            arr[j][k]=-1;
                        }
                    }
                }
            }
        }
    }
    
    
    
    
    
    
}