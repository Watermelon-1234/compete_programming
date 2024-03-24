#include<iostream>
using namespace std;
bool is_leap_year(int year)
{
    if(year%400==0) return 1;
    else if(year%100==0) return 0;
    else if(year%4==0) return 1;
    else return 0; 
}
int date_of_month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int date_of_month_leap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int days_calculate(int y,int m,int d,int y_prev)
{
    for(int i=(y<y_prev?y:y_prev);i<(y<y_prev?y_prev:y);i++)//for year
    {
        d+=is_leap_year(i)? 366: 365;
        //cout<<"d="<<d<<endl;
    }
    for(int i=0;i<m-1;i++)//for month
    {
        d+=is_leap_year(y)?date_of_month_leap[i]:date_of_month[i];        
        //cout<<"d="<<d<<endl;
    }
    return d;
}

int main()
{
    int y,y2,y_prev,m,d,sum1=0;

    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    while(cin>>y>>m>>d)
    {
        //cout<<y<<" "<<m<<" "<<d<<endl;
        cin>>y2;
        y_prev=y<y2?y:y2;
        sum1=days_calculate(y,m,d,y_prev);
        cin>>m>>d;
        // cout<<"sum1="<<sum1<<endl;
        // cout<<"sum2="<<days_calculate(y2,m,d,y_prev)<<endl;
        cout<<abs(sum1-days_calculate(y2,m,d,y_prev))<<endl;
    }
}