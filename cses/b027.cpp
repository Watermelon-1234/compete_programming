#include <iostream>
using namespace std;
int main()
{
    int food,drink;
    cin>>food>>drink;
    if(food<=0||drink<=0){
        cout<<"錯誤";
    }
    else if(food+drink>200)
    {
        cout<<"離開";
    }
    else if(food+drink>150)
    {
        cout<<"不買飲料";
    }
    else
    {
        cout<<"訂購";
    }
}