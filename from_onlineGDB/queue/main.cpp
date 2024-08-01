#include <iostream> 
using namespace std;
void insertQueue(int); 
void deleteQueue (); 
int firstOne();
#define size 90000
struct Queue{ 
    int q[size];
    int back; 
    int front;
    Queue(){ back=-1,front=-1;}
};
Queue qu; 
int main()
{
    int a,b,N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b;
            insertQueue(b);
        }
        else if(a==2)
        {
            cout<<firstOne()<<endl;
        }
        else if(a==3)
        {
            deleteQueue();
        }
    }
    
    
}
void insertQueue (int n)
{ 
    qu.q[(++qu.back)%size]=n; 
} 
void deleteQueue ()
{ 
    if(qu.front != qu.back) 
    { 
        qu.front++;
    } 

} 
int firstOne()
{
    if(qu.front == qu.back) 
    {
        return -1; 
        
    } 
    else 
    { 
        return qu.q[(qu.front+1)%size];
    } 
}












