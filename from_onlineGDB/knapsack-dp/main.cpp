#include<iostream>

using namespace std;

int main()
{
    for(;;)
    {
        cout<<"先輸入背包負重能力 然後再輸入物品個數 再輸入各個物品的重量與價格"<<endl;
        int w,v,n,ks;
        cin>>ks>>n;
        long int knap[ks+1][n+1]={};//[k][1]行開始記錄 
        for(int i=0;i<n;i++)//第i個東西要放在[k][i+1] 
        {
            cin>>w>>v;
            for(int j=ks;j>=1;j--)
            {
                /*j-w>0
                w>j break
                */
                if(w>j)
                {
                    break;
                }
                if(knap[j][0]>knap[j-w][0]+v)
                {
                    
                }
                else
                {
                    knap[j][0]=knap[j-w][0]+v;
                    for(int k=1;k<=i;k++)
                    {
                    	knap[j][k]=0;
                    	if(knap[j-w][k]>0)
                    	{
                    		knap[j][k]=knap[j-w][k];
						}
					}
					knap[j][i+1]=w;
                }
            }
        }
        cout<<endl;
        cout<<"結果(放的物的重量):"<<knap[ks][0]<<endl<<endl; 
		//cout<<knap[ks][0]<<endl;
        for(int i=1;i<=n;i++)
        {
        	cout<<knap[ks][i]<<endl;
		}
        
        
        cout<<"-----------------"<<endl;
    }
}



