#include<iostream>
using namespace std;
int main(){
    int n,m;
    while(cin >> n >> m)
    {
        
        int a[m][n];
        for(auto i=0;i<n;i++)
        {
            for(auto j=0;j<m;j++)
            {
                cin>>a[j][i];
            }
        }
        for(auto i=0;i<m;i++)
        {
            for(auto j=0;j<n;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}