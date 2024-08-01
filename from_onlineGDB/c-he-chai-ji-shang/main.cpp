#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    /*int a,b;   和差機商
    cout <<"輸入一數,再空格打另一個數"<<endl;
    cin >> a >> b;
    cout << a <<"與"<< b <<"的和為"<<a+b<<endl;
    cout << a <<"與"<< b <<"的差為"<<a-b<<endl;
    cout << a <<"與"<< b <<"的積為"<<a*b<<endl;
    cout << a <<"與"<< b <<"的商為"<<a/b<<endl;
    cout << a <<"的"<< b <<"次方為"<<pow(a,b)<<endl;*/
    /*float a,c,b=3.14;  半徑 圓
    cout<<"輸入圓的半徑"<<endl;
    cin>>a;
    cout<<"圓的面積為"<<a*a*b<<endl;
    cout<<"圓的周長為"<<a*2*b<<endl;*/
    int a,b;
    while(1)
    {
        cout<<"請問要輸入民國年還是西元年?(民國年打1西元年打2)"<<endl;
        cin>>a;
        if(a==1)
        {
            cout<<"請輸入年分"<<endl;
            cin>>b;
            cout<<"結果是"<< b+1911<<"年"<<endl;
        }
        if(a==2)
        {
        
            cout<<"請輸入年分"<<endl;
            cin>>b;
            cout<<"結果是民國"<< b-1911<<"年"<<endl;
        }
        cout<<"還要繼續嗎?(繼續按1,結束按2)"<<endl;
        cin>>a;
        if(a==1)
        {
            cout<<"好DER!"<<endl;
            continue;
        }
        else
        {
            cout<<"感謝你的使用"<<endl;
            break;
        }
        
    }
    
}

