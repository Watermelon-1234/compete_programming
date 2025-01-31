#include<bits/stdc++.h>
using namespace std;
#define _int int64_t
#define fastio ios::sync_with_studio(1); cin.tie(0);
_int M,N,k,r,c,score = 0,gem = 0;
_int arr[101][101]={};
vector<_int> direct ={0,1};

void turn()
{
    direct = {direct[1], -1 * direct[0]};
    // cout<<direct[0]<<direct[1];
}

int main()
{
    cin >> M >> N >> k >> r >> c;
    for(_int i = 0;i < M;i++)
    {
        for(_int j = 0;j<N;j++)
        {
            cin >> arr[i][j];
            // cout<<i<<j;
        }
    }
    // cout<<arr[0][0];
    // cout<<"--------------------"<<endl;
    while(arr[r][c]!=0)
    {
        // cout<<"yee";
        gem++;
        
        // for(int i = 0 ;i<M;i++)
        // {
        //     for(int j = 0 ;j<N;j++)
        //     {
        //         if(arr[i][j]==-1){ cout<<"x ";}
        //         else{cout<<arr[i][j]<<" ";}
        //     }
        //     cout<<endl;
        // }
        // cout<<endl<<score<<" "<<r<<" "<<c<<endl;
        // cout<<direct[0]<<" "<<direct[1]<<endl;
        // cout<<"-------------------"<<endl;
        score += arr[r][c];
        arr[r][c]--;
        if(score % k ==0)
        {
            turn();
        }
        while(r+direct[0] >= M || r+direct[0] <0 || c + direct[1] >= N || c + direct[1] < 0 || arr[r+direct[0]][c+direct[1]]==-1)
        {
            turn();
        }
        r+=direct[0];
        c+=direct[1];
    }
    cout << gem;
}
/*
4 5 2 2 1
2 0 1 1 1
2 -1 0 2 -1 
0 3 2 3 0
1 1 -1 3 1
*/