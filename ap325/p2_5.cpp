/*input
6
123456789
100
-1
*/
#include<bits/stdc++.h>
using namespace std;
#define int int64_t
#define fastio ios::sync_with_stdio(0)
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n"
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define MOD 1000000007

class matrix
{
    public:
        pii x1;
        pii x2;
        matrix();
        matrix(pii,pii);
        matrix operator* (matrix);

};

matrix::matrix(pii a,pii b)
{
    x1 = a;
    x2 = b;
}

matrix::matrix()
{
    x1 = mp(1,0);
    x2 = mp(0,1);
}

matrix matrix::operator*(matrix b)
{
    matrix tmp;
    tmp.x1.F = (((x1.F%MOD) * (b.x1.F%MOD))%MOD + ((x1.S%MOD) * (b.x2.F%MOD))%MOD)%MOD;
    tmp.x1.S = (((x1.F%MOD) * (b.x1.S%MOD))%MOD + ((x1.S%MOD) * (b.x2.S%MOD))%MOD)%MOD;
    tmp.x2.F = (((x2.F%MOD) * (b.x1.F%MOD))%MOD + ((x2.S%MOD) * (b.x2.F%MOD))%MOD)%MOD;
    tmp.x2.S = (((x2.F%MOD) * (b.x1.S%MOD))%MOD + ((x2.S%MOD) * (b.x2.S%MOD))%MOD)%MOD;
    return tmp;
}


matrix base(mp(1,1),mp(1,0));

matrix fast_pow(matrix x,int y)
{
    if(y<2)
    {
        return base;
    }
    if(y & 1)
    {
        return fast_pow(x,y-1)*x;
    }
    matrix t = fast_pow(x,y/2);
    return (t*t);
}



int input;

signed main()
{
    fastio;
    while(cin>>input)
    {
        if(input == -1)
        {
            return 1;
        }
        matrix a = base;
        cout<<fast_pow(a,input-1).x1.F<<endl;
    }

}

