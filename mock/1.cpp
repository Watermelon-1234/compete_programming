#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,best=101,worst=-1;
    cin>>n;
    int score[n]={};
    for(int i=0;i<n;i++)
    {
        cin>>score[i];
        if(score[i]<60&&score[i]>worst)
        {
            worst=score[i];
        }
        if(score[i]>=60&&score[i]<best)
        {
            best=score[i];
        }
    }
    cout<<"test1"<<endl;
    sort(score,score+n);
    cout<<"test2"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<score[i]<<" ";
    }
    cout<<endl;
    worst!=-1 ? printf("%d\n",worst) : printf("best case\n");
    best!=101 ? printf("%d\n",best) : printf("worst case\n");
    
}