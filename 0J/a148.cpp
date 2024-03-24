#include<iostream>
using namespace std;
int main(){
    float std_dev=0;
    int n,input;
    while(cin >> n)
    {
        int n_=n;
        float std_dev=0;
        while(n--) {
            cin>>input;
            std_dev+=(input-59);
        }
        std_dev/n_ > 0 ? cout << "no" : cout << "yes";
        cout<<endl;
    }
    
}