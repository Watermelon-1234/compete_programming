#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define _int int64_t
_int n,w1,w2,h1,h2,input,sum = 0,current,ps[11]={},_max = 0,dh,v1,v2,h3;
bool skip = 0;
_int find_h(_int v)
{

    if(v <= v1)
    {
        sum = v / (w1 * w1);
    }
    else if(v > v1 && v <= v2)
    {
        sum = ( h1 + ((v - v1) / (w2 * w2) ));
    }
    else{
        sum = h3;
    }
    return sum;
};

int main()
{
    fastio;
    cin >> n >> w1 >> w2 >> h1 >> h2;
    v1 = w1 * w1 * h1,v2 = w2 * w2 * h2 + v1;
    h3 = h1 + h2;

    for(int i = 1;i <= n;i++)// 1 base
    {
        cin >> input;
        ps[i] = ps[i-1] + input;
        if(ps[i] >= v2)
        {
            ps[i] = v2;
            skip = 1;
        }
        if(i==n) skip = 1;
        dh = find_h(ps[i]) - find_h(ps[i-1]);
        if(dh > _max) _max = dh;
        if(skip)
        {
            cout << _max ;
            return 0;
        }
    }
    // cout<<_max;
}