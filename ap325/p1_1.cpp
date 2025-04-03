/*input
g g g f g 256 f 228 421 910 g 47 g 117 g g 692 -18 -420
*/

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

string t;
int f(int x)
{
    return 2*x - 1;
}

int g(int x,int y)
{
    return x + 2*y - 3;
}

int get_char()
{
    cin>>t;
    int x,y;
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