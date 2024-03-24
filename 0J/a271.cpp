#include<iostream>
#include<cstdlib>
#include<sstream>
using namespace std;
struct Rabbit
{
    int x,y,z,w,n,m,poi=0;//x=紅+  y=白+ z=黃- w=黑- n=毒- m=體重 poi:總毒量
    bool is_dead=0;

    Rabbit(int _x,int _y,int _z,int _w,int _n,int _m);
    void echo()
    {
        printf(" x %d\n y %d\n z %d\n w %d\n n %d\n m %d\n",x,y,z,w,n,m);
    }
    void print_mass()
    {
        if(m<=0) cout<<"bye~Rabbit"<<endl;
        cout<<m<<"g"<<endl;
    }
    void routine();
    void red_carrot();
    void white_carrot();
    void yellow_carrot();
    void black_carrot();
    void actions(int act)//早上先中毒，晚上才吃東西。
    {
        routine();
        if (m <= 0) {
            return; // 兔子体重小于等于0，结束处理
        }

        switch (act)
        {
            case 0:
            {
                break;
            }
            case 1:
            {
                red_carrot();
                break;
            }
            case 2:
            {
                white_carrot();   
                break;
            }
            case 3:
            {
                yellow_carrot();
                break;
            }
            case 4:
            {
                black_carrot();
                break;
            }
        }
    }    
        
};

Rabbit::Rabbit(int _x,int _y,int _z,int _w,int _n,int _m)
{
   x=_x;
   y=_y;
   z=_z;
   w=_w;
   n=_n;
   m=_m; 
}

void Rabbit::routine()
{
    m-=poi;
    // cout<<"routine: m="<<m<<endl;
    if(m<=0)
    {   
        // cout<<"out out"<<endl;
        return;
    }
}
void Rabbit::red_carrot()
{
    m+=x;
}
void Rabbit::white_carrot()
{
    m+=y;
}
void Rabbit::yellow_carrot()
{
    m-=z;
    if(m<=0)
    {
        return;
    }
}
void Rabbit::black_carrot()
{
    m-=w;
    poi+=n;
    if(m<=0)
    {
        return;
    }
}

int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        
        int _a,b,c,d,e,f;
        cin>>_a>>b>>c>>d>>e>>f;//5 3 2 4 3 10
        stringstream ss;//1 1 2 3 3 3 3 4 3 3 2 2 2 2 2 2
        Rabbit a(_a,b,c,d,e,f);
        cin.ignore();
        string line;
        getline(cin,line);
        ss.str("");
        ss.clear();
        ss<<line;
        while(true)
        {
            int input;
            ss>>input;
            if(ss.fail()) 
            {
                a.print_mass();
                //a.echo();
                break;
            }
            a.actions(input);
            if(a.m<=0)
            {
                cout<<"bye~Rabbit"<<endl;
                break;
            }
        }    
    }
}