#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n/*row*/,m/*column*/;
    cin>>n>>m;
    int num=0;
    int a[n][m];
    queue<pair<int,int>> ans;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int max_range = a[i][j];
            int sum = 0;
            // for(int k=-max_range+i;k<=max_range+i;k++)
            // {
            //     if(k>=0&&k<m)
            //     {
            //         int width=max_range-abs(k);
            //         for(int l=-width+j; l<=width+j;l++)
            //         {
            //             if(l>=0&&l<n)
            //                 sum+=a[k][l];
            //         }
            //     }
            // }
            for(int k=-max_range;k<=max_range;k++)
            {
                if(k+i>=0&&k+i<n)
                {
                    int width=max_range-abs(k);
                    for(int l=-width;l<=width;l++)
                    {
                        if(l+j>=0&&l+j<m)
                        {
                            sum+=a[k+i][l+j];
                        }
                    }
                }
            }
            if(sum%10==max_range)
            {
                ans.push({i,j});
                num++;
            }
        }
    }
    cout<<num<<endl;
    while(!ans.empty())
    {
        pair<int,int> output=ans.front();
        ans.pop();
        cout<<output.first<<" "<<output.second<<endl;
    }
