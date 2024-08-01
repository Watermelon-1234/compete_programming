#include <iostream>
#include <string>
using namespace std;

int abs_calculate(int a,int b);
int rome_to_num(string a);
string num_to_rome(int a);

int main()
{
    string a,b,end_ch;
    cin>>a>>b>>end_ch;
    cout<<num_to_rome(a);
    //cout<<num_to_rome(abs_calculate(a,b));
}

int abs_calculate(a,b)
{
    num=rome_to_num(a)-rome_to_num(b);
    return abs(num);
}

int rome_to_num(string a){
    int num[1000],sum;
    for(int i=0;i<length(a);i++)
    {
        /*
        I	1
        V	5
        X	10
        L	50
        C	100
        D	500
        M	1,000
        */
        switch(a[i])
            case "I":
                num[i]=1;
            case "V":
                num[i]=5;
            case "X":
                num[i]=10;
            case "L":
                num[i]=50;
            case "C":
                num[i]=100;
            case "D":
                num[i]=500;
            case "M":
                num[i]=1000;
    }
    for(int i=length(a)-1;i>0;i--)
    {
        if(i==length(a))
        {
            sum+=num[i];
        }
        if(num[i]<num[i-1])
        {
            sum-=num[i+1];
        }
        else
        {
            sum+=num[i-1];
        }
    }
    return sum;
}