#include<iostream>
#include <stdlib.h> /* 亂數相關函數 */
#include <time.h>   /* 時間相關函數 */
#include <limits>
#include <string>
using namespace std;
int unsorted[1000];
int size;
string input;
bool yes=0,_yes=0;

void _sort(int start_index,int end_index);
void _devive(int start_index,int end_index);
void print();
void put(bool right,int size,int dead);

int left_index=0;
int left_size;
int devive_left[1000];

int right_size;
int devive_right[1000];
int right_index=0;

int main()
{

    cin>>size;
    for(int i=0;i<size;i++)
    {
        unsorted[i]=i+1;
    }
    _devive(0,size-1);

}

void _sort(int start_index,int end_index)//marge
{
    
    int left_index=0;
    int left_size=(start_index+end_index)/2-start_index+1;
    int devive_left[left_size];
    
    int right_size=end_index-(start_index+end_index)/2;
    int devive_right[right_size];
    int right_index=0;
    
    for(int i=0;i<left_size;i++)
    {
        devive_left[i]=unsorted[i+start_index];
        cout<<devive_left[i]<<" ";
    }
    
    for(int i=0;i<right_size;i++)
    {
        devive_right[i]=unsorted[i+left_size+start_index];
        cout<<devive_right[i]<<" ";
    }
    cout<<endl;
    while(1)
    {
        put(0,0,left_size+right_size);
        put(1,0,left_size+right_size);
    }
}

void _devive(int start_index,int end_index)
{
    if((end_index - start_index)==0)
    {
    
    }
    else
    {
        _devive(start_index,(start_index+end_index)/2);
        _devive((start_index+end_index)/2+1,end_index);
        _sort(start_index,end_index);
    }
}

void put(bool right,int size,int dead)
{
    if(yes||_yes)
    {
        if(size==dead)
        {
            for(int i=0;i<dead;i++)
            {
                cout<<unsorted[i];
                if(i!=dead-1)
                {
                    cout<<" ";
                }
            }
            cin>>input; 
            if(input=="Gotowe")
            {
                _yes=1;
            }
            if(input=="Tak")
            {
                yes=1;
            }
            
        }
        else
        {
            if(right)
            {
                
                
                {
                    unsorted[start_index+left_index+right_index]=devive_right[right_index];
                    
                    right_index++;
                    if(right_index==right_size)
                    {
                        
                        devive_right[right_index]=std::numeric_limits<int>::max();
                    }
                }
            }
            else
            {
                unsorted[start_index+left_index+right_index]=devive_left[left_index];
                
                left_index++;
                if(left_index==left_size)//左邊滿了
                {
                    
                    devive_left[left_index]=std::numeric_limits<int>::max();
                }
            }
        }
    }
}





