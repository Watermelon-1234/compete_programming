#include<iostream>
#include <algorithm>

using namespace std;
int size,m;
int arr[10000]={};
int index[10000]={};
void set_get(int last,int num);
int main()
{
    cout<<"cin>>n>>m>>arr[n]"<<endl;
    while(cin>>size>>m)
    {
        if(size>=m)
        {
            for(int i =0;i<size;i++)
            {
                cin>>arr[i];
            }
            sort(arr,arr+size);
            set_get(0,0);
            
            for(int i =0;i<size;i++)
            {
                arr[i]=index[i]=0;
            }
        }
        else
        {
            cout<<"輸入錯誤"<<endl;
        }
        cout<<endl;
        cout<<"cin>>n>>m>>arr[n]"<<endl;
    }
}
void set_get(int last,int num)
{
    if(last==m)
    {
        for(int i=0;i<m;i++)
        {
            cout<<arr[index[i]]<<"　";
        }
        cout<<endl;
    }
    else
    {
        for(int i=num;i<size;i++)
        {
            index[last]=i;
            set_get(last+1,i+1);
        }
    }
    
    
}