#include <iostream>
#include <algorithm>
struct work
{
    int start;
    int end;
};
bool cmp(work a,work b)
{
    return a.end<b.end;
}
using namespace std;
int main()
{
    int size,count,last;
    work works[1000];
    while(1)
    {
        for(int i=0;i<1000;i++)
        {
            works[i].start=works[i].end=0;
        }
        count=1;
        last=0;
        cin>>size;
        for(int i=0;i<size;i++)
        {
            cin>>works[i].start>>works[i].end;
        }
        sort(works,works+size,cmp);
        for(int i=1;i<size;i++)
        {
            if(works[last].end<=works[i].start)
            {
               count++;
               last=i;
            }
        }
        cout<<count;
    }
}
