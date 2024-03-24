#include<iostream>
using namespace std;

int main()
{
    int year;
    while (cin>>year)
    {
        if(year ==0)
        {
            break;
        }
        if(year % 400 ? (year % 100 ? (year % 4 ? (false) : (true)) : (false)) : true)
        {
            cout<<"a leap year"<<endl;
        }
        else{
            cout<<"a normal year"<<endl;
        }
    }
}