#include<iostream>
#include<string>
using namespace std;
long long fast_power(int a,int n)
{
    if(n==0)
        return 1;
    long long res=fast_power(a,n/2);
    if(n%2)return res*res*a;
    return res*res;
}
int main() {
   cout<<fast_power(2,30);
}
