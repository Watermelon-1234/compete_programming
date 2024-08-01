#include<iostream>
using namespace std;
int _max=0,lim=0;
int size,v[10000]={},w[10000]={};
void choose(int index,int is_choose,int sum,int last_index)//(size-1)
{
    if(index=last_index)//end
    {
        //1
        if(sum+w[index]>lim)
        {
            //stop
            if(sum>_max)//等同0
            {
                _max=sum;
            }
            
        }
        else
        {
            if(sum+w[index]>_max)
            {
                _max=sum+w[index];
            }
        }
    }//炸了
    else if(is_choose)
    {
        if(sum+w[index]>lim)
        {
            //stop
            if(sum>_max)
            {
                _max=sum;
            }
            
        }
        else
        {
            sum+=w[index];
            choose(index+1,0,sum,last_index);
            choose(index+1,1,sum,last_index);
        }
    }
    else if(!is_choose)
    {
        choose(index+1,0,sum,last_index);
        choose(index+1,1,sum,last_index);
    }
}

int main()
{
    while(1)
    {
        int size,v[10000]={},w[10000]={};
        _max=0;
        lim=0;
        cin>>lim;
        cin>>size;
        
        for(int i=0;i<size;i++)
        {
            cin>>w[i]>>v[i];
        }
        
        
        choose(0,0,0,size-1);
        choose(0,0,1,size-1);
        cout<<_max<<endl;
    }
}