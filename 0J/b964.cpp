#include<bits/stdc++.h>
using namespace std;

vector<int> vec;
int n;
int worse = -1;
int better = 101;

int main()
{
    cin >> n;
    while(n--)
    {
        int i;
        cin >>i;
        vec.push_back(i);
    }
    sort(vec.begin(),vec.end());
    
    for(auto i:vec)
    {
        printf("%d ",i);
        if(i<60)
        {
            if(i>worse)
            {
                worse = i;
            }
        }
        else if(i<better)
        {
            better = i;
        }
    }
    if(worse == -1)
    {
        printf("\nbest case");
    }
    else
    {
        printf("\n%d",worse);
    }
    if(better ==101)
    {
        printf("\nworst case");
    }
    else
    {
        printf("\n%d",better);
    }
    


    
    
    return 0;

}