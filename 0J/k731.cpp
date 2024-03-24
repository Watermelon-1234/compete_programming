#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,left=0,right=0,ret=0;
    cin>>n;
    int dir[n+1]={},pos[n+1][2]={},facing[n+1][2]={};//x-y
    for(int i=1;i<=n;i++)
    {

        for(int j=0;j<2;j++)
        {
            cin>>pos[i][j];
            facing[i][j]=pos[i][j]-pos[i-1][j];
        }
        if(!facing[i][0])//n/s
        {
            if(facing[i][1]>0)
            {
                dir[i]=1;
            }
            else
            {
                dir[i]=3;
            }
        }
        else
        {
            if(facing[i][0]>0)
            {
                dir[i]=2;
            }
            else
            {
                dir[i]=4;
            }
        }
        if(i>=2)
        {
            // 計算左轉、右轉、迴轉的次數
            if (i >= 1) {
                int diff = dir[i] - dir[i - 1];
                if (diff < 0) diff += 4; // 處理方向差的正規化

                if (diff == 1) {
                    right++;
                } else if (diff == 3) {
                    left++;
                } else if (diff == 2) {
                    ret++;
                }
            }
        }
    }
    printf("%d %d %d",left,right,ret);
}