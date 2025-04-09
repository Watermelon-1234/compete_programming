/*input
2020020100010
8
*/
#include<bits/stdc++.h>
using namespace std;

#define int int64_t

int n,i=-1;
string s;

int solve(int size)
{
    i++;
    if(size<1) return 0;
    if(s[i] == '2')
    {
        int tmp1 = solve(size/2);
        int tmp2 = solve(size/2);
        int tmp3 = solve(size/2);
        int tmp4 = solve(size/2);
        return tmp1 + tmp2 + tmp3 + tmp4;
    }
    if(s[i] == '1')
    {
        return size*size;
    }
    else // s[i] = 0
    {
        return 0;
    }
}

signed main()
{
    cin>>s>>n;
    cout<<solve(n);    
    
}