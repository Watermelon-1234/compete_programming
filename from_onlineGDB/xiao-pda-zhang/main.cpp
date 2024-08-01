#include <iostream>
#include <algorithm>
using namespace std;
int N,sum=0;

struct solider
{
    int r,s;
};
bool cmp1(solider a,solider b)
{
    if(a.s==b.s)
    {
        return a.r<b.r;
    }
    else
    {
        return a.s<b.s;
    }
}


solider sol[300000];

int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>sol[i].s;
    }
    for(int i=0;i<N;i++)
    {
        cin>>sol[i].r;
    }
    sort(sol,sol+N,cmp1);
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i-sol[j].r>=0)
            {
                solider temp;
                temp.r=sol[i-j].r;
                temp.s=sol[i-j].s;
                sol[i-j].r=sol[j].r;
                sol[i-j].s=sol[j].s;
                sol[j].r=temp.r;
                sol[j].s=temp.s;
            }
        }
        sum=0;
        for(int j=0;j<N;j++)
        {
            if(j<i&&j+sol[j].r-1<=i)
            {
                sum+=sol[j].s;
            }
            if(j>i)
            {
                sum+=sol[j].s;
            }
        }
        cout<<sum<<" ";
    }
}