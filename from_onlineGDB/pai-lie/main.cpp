#include<iostream>
#include <algorithm>

using namespace std;
int size;
int arr[10000]={};
int index[10000]={};
void set_get(int last);
int main()
{
    cout<<"cin>>n>>m>>arr[n]"<<endl;
    while(cin>>size)
    {
        for(int i =0;i<size;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+size);
        set_get(0);

        for(int i =0;i<size;i++)
        {
            arr[i]=index[i]=0;
        }
        cout<<endl;
        cout<<"cin>>n>>arr[n]"<<endl;
    }
}
void set_get(int last)
{
    if(last==size)
    {
        for(int i=0;i<size;i++)
        {
            cout<<arr[index[i]]<<"　";
        }
        cout<<endl;
    }

    {
        for(int i=0;i<size;i++)
        {
            bool r=1;
            for(int j=0;j<last;j++)
            {
                if(i==index[j])
                {
                    r=0;
                    break;
                }
            }
            if(r)
            {
                index[last]=i;
                set_get(last+1);
            }
        }
    }


}

