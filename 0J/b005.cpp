#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        bool col[n]={},row[n]={};
        int r=0,c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                bool input;
                cin>>input;
                if(input)//這要怎麼用邏輯寫
                {
                    col[i]=!col[i];
                    row[j]=!row[j]; 
                }
                
            }
        }// i 列第 j 行(從1,1算)
        for(int i=0;i<n;i++)
        {
            if(col[i])
            {
                if(c)
                {
                    //cout<<"Corruptc";
                    c=n+1;
                    break;
                }   
                else{
                    c=i+1;
                }
            }
            if(row[i])
            {
                if(r)
                {
                    //cout<<"Corruptr";
                    r=n+1;
                    break;
                }
                else{
                    r=i+1;
                }
            }
        }
        if(r==0&&c==0)
        {
            cout<<"OK"<<endl;
        }
        else if(r==0||c==0||r>n||c>n)
        {
        cout<<"Corrupt"<<endl;
        }
        else
        {
            printf("Change bit (%d,%d)\n",c,r);
        }

    }
}