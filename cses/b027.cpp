#include <iostream>
using namespace std;
int main()
{
    int food,drink;
    cin>>food>>drink;
    if(food<=0||drink<=0){
        cout<<"���~";
    }
    else if(food+drink>200)
    {
        cout<<"���}";
    }
    else if(food+drink>150)
    {
        cout<<"���R����";
    }
    else
    {
        cout<<"�q��";
    }
}