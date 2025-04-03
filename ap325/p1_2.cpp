/*input
h f 5 g 3 4 3
*/

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

string t;
int f(int x)
{
    return 2*x - 3;
}

int g(int x,int y)
{
    return 2*x + y - 7;
}

int h(int x,int y,int z)
{
    return 3*x - 2*y + z;
}

int get_char()
{
    cin>>t;
    int x,y,z;
    switch (t[0])
    {
        case 'f':
            return f(get_char());
            break;
        case 'g':
            x = get_char();
            y = get_char();
            return g(x,y);
            break;
        case 'h':
            x = get_char();
            y = get_char();
            z = get_char();
            return h(x,y,z);
            break;
        default:
            return stoi(t);
            break;
    }
}



signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<get_char();
}