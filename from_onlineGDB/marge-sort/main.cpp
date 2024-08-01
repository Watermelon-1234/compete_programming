#include<iostream>
#include <stdlib.h> /* 亂數相關函數 */
#include <time.h>   /* 時間相關函數 */
#include <limits>
using namespace std;
int unsorted[10000];
int size;

void _sort(int start_index,int end_index);
void _devive(int start_index,int end_index);
void print();


int main()
{
    while(1)
    {
        srand(time(NULL));
        cout<<"輸入想排序次數"<<endl;
        cin>>size;
        cout<<"unsorted: ";
        for(int i=0;i<size;i++)
        {
            unsorted[i]=(rand()%10000)+1;
            cout<<unsorted[i]<<",";
        }
        cout<<endl<<"**************************"<<endl;
        _devive(0,size-1);
        print();
        cout<<endl;
    }
}

void _sort(int start_index,int end_index)//marge
{
    cout<<endl<<"**************************"<<endl;
    int left_index=0;
    int left_size=(start_index+end_index)/2-start_index+1;
    int devive_left[left_size];
    
    int right_size=end_index-(start_index+end_index)/2;
    int devive_right[right_size];
    int right_index=0;
    cout<<"left_block : ";
    for(int i=0;i<left_size;i++)
    {
        devive_left[i]=unsorted[i+start_index];
        cout<<devive_left[i]<<" ";
    }
    cout<<endl<<"right_block : ";
    for(int i=0;i<right_size;i++)
    {
        devive_right[i]=unsorted[i+left_size+start_index];
        cout<<devive_right[i]<<" ";
    }
    cout<<endl;
    while(1)
    {
        if(left_index==left_size&&right_index==right_size)
        {
            cout<<"end"<<endl;
            cout<<endl<<"**************************"<<endl;
            break;
        }
        
        
        if(devive_left[left_index]<devive_right[right_index])//左邊小放左邊
        {
            unsorted[start_index+left_index+right_index]=devive_left[left_index];
            cout<<"left_put: "<<devive_left[left_index]<<endl;
            left_index++;
            if(left_index==left_size)//左邊滿了
            {
                cout<<"left_full"<<endl;
                devive_left[left_index]=std::numeric_limits<int>::max();
            }
        }
        else if(devive_left[left_index]>devive_right[right_index])
        {
            unsorted[start_index+left_index+right_index]=devive_right[right_index];
            cout<<"right_put: "<<devive_right[right_index]<<endl;
            right_index++;
            if(right_index==right_size)
            {
                cout<<"right_full"<<endl;
                devive_right[right_index]=std::numeric_limits<int>::max();
            }
        }
        
        
    }
}

void _devive(int start_index,int end_index)
{
    if((end_index - start_index)==0)
    {
        cout<<start_index<<" "<<end_index<<" wait for sort"<<endl;    
    
    }
    else
    {
        cout<<start_index<<" "<<end_index<<" cutting"<<endl;
        _devive(start_index,(start_index+end_index)/2);
        _devive((start_index+end_index)/2+1,end_index);
        _sort(start_index,end_index);
    }
}

void print()
{
    cout<<"sorted: ";
    for(int i=0;i<size;i++)
    {
        cout<<unsorted[i]<<" ";
    }
    cout<<endl;
    cout<<"---------------------"<<endl;
}




