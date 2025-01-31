#include<bits/stdc++.h>
#define int int64_t
#define F first
#define S second
using namespace std;


int q,idx;
string a,input,b1,b2;

signed main()
{
    cin>>a>>q;
    while(q--)
    {
        
        cin >> b1 >> b2 >> b2;
        // cout << b1 << endl <<b2 <<endl;
        if(a.find(b1) != -1)
            a.replace(a.find(b1),b1.length(),b2);
            // cout<<a<<endl;

    }
    cout<<a;
    

}