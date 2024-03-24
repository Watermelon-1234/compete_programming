#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--)
    {
        int sum=1,input;
        cin>>input;
        if(input==0)
        {
            cout<<input;
            return 0;
        }
        while(input)
        {
            sum*=(input%10);
            input/=10;
        }
        cout<<sum<<endl;
    }
    
}