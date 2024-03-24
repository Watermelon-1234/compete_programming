#include<bits/stdc++.h>

using namespace std;

int n,k;
int superior=0;
int main()
{
    cin>>k>>n;
    vector<vector<int>> matrix;
    for(int i=0; i<k; i++)
    {
        vector<int> row;
        for(int j=0; j<n; j++)
        {
            int temp;
            cin>>temp;
            row.push_back(temp);
        }
        matrix.push_back(row);
    }
    // cout<<"yee";
    // for(int i=0;i<k;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<matrix[1][1];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
        bool breaked=0;
            for(int l=0;l<k-1;l++)
            {
                if((matrix[l][i]-matrix[l][j])*(matrix[l+1][i]-matrix[l+1][j])>0)
                {
                    breaked=1;
                    break;
                }
            }
            if(breaked)
            {
                superior++;
            }
        }
    }
    cout<<superior;
}

