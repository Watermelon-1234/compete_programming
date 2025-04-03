/*input
4 10
1 2 4 6
*/

#include<bits/stdc++.h>
using namespace std;

#define int int64_t
int N,L;
vector<int> p(500000,0);

int cost(int left,int right)
{
    if(right - left <= 1) // a segment without cutpoint is no need to cut
    {
        return 0;
    }
    int m = left+1,mid = (p[right] + p[left])/2;
    // cout<<m<<" "<<right<<" "<<left<<endl;
    while(p[m]<mid) m++;
    // now p[m] is the smallest one bigger than mid
    if(p[m-1]-p[left] >= p[right]-p[m]) m--;

    return p[right] - p[left] + cost(left,m) + cost(m,right);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>L;
    p[0] = 0;
    p[N+1] = L;
    for(int i = 1;i<=N;i++)
    {
        int t;
        cin>>t;
        p[i] = t;
    }
    cout << cost(0,N+1); // [0,N+1]
}