#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    long long score=0;
    cin>>n>>m;
    int a[n][m];
   
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    
    for(int h=0;h<=m*n;h++)
    {
        stack<int> col[m];    
        stack<int> row[n];    
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //printf("a[%d][%d]=%d:",i,j,a[i][j]);
                if(a[i][j]==-1)
                {
                    //cout<<"continue"<<endl;
                    continue;
                }
                if(row[i].empty())
                {
                    row[i].push(a[i][j]);
                    //printf("row[%d] is empty,push()\n",i);
                }
                else if(row[i].top()==a[i][j])
                {
                    a[i][j]=-1;
                    int h=j;
                    while(h--)
                    {
                        if(a[i][h]==row[i].top())
                        {
                            a[i][h]=-1;
                            break;
                        }
                    }
                    ////cout<<row[i].top()<<endl;
                    score+=row[i].top();
                    row[i].pop();
                    //cout<<"row["<<i<<"]:paired score="<<score<<endl;
                }
                else
                {
                    //cout<<"row["<<i<<"]:not paired top="<<row[i].top()<<endl;
                    row[i].push(a[i][j]);
                    

                }
                for(int k=0;k<n;k++)
                {
                    for(int l=0;l<m;l++)
                    {
                        //cout<<a[k][l]<<" ";
                    }
                    //cout<<endl;
                }
            }
        }
        //cout<<"----------------------------------------------------------------"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //printf("a[%d][%d]=%d:",i,j,a[i][j]);
                if(a[i][j]==-1)
                {
                    //cout<<"continue"<<endl;
                    continue;
                }
                if(col[j].empty())
                {
                    col[j].push(a[i][j]);
                    //printf("col[%d] is empty,push()\n",j);
                }
                else if(col[j].top()==a[i][j])
                {
                    a[i][j]=-1;
                    int h=i;
                    while(h--)
                    {
                        if(a[h][j]==col[j].top())
                        {
                            a[h][j]=-1;
                            break;
                        }
                    }
                    score+=col[j].top();
                    //cout<<"col["<<j<<"]:paired score="<<score<<endl;
                    col[j].pop();
                }
                else
                {
                    //cout<<"col["<<j<<"]:not paired top="<<col[j].top()<<endl;
                    col[j].push(a[i][j]);

                }
                
                for(int k=0;k<n;k++)
                {
                    for(int l=0;l<m;l++)
                    {
                        //cout<<a[k][l]<<" ";
                    }
                    //cout<<endl;
                }
            }
        }
        //cout<<"****************************************************************"<<endl;
    }
    cout<<score;
        
}