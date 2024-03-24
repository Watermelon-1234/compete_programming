#include<bits/stdc++.h>

using namespace std;
int main()
{
    float weight,height;
    cin>>height>>weight;
    float BMI=weight/pow(height/100,2);
    if(BMI>=27)
    {
        cout<<"肥胖";
    }
    else if(BMI>=24)
    {
        cout<<"過重";
    }
    else if(BMI>=18.5)
    {
        cout<<"健康";
    }
    else
    {
        cout<<"過輕";
    }
}