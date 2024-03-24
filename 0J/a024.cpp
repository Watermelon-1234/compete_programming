#include <iostream>
using namespace std;
int get_gcd(int x, int y)
{
    if(x<y) swap(x,y);
    if(x%y==0) return y;
    else return get_gcd(x-y,y);
}
void swap(int &x, int &y)
{
    //swap(x,y)
    int temp;
    temp = x;
    x=y;
    y=temp;
}
int main()
{
    int x,y;
    cin >> x >> y;
    cout<<get_gcd(x,y)<<endl;
}