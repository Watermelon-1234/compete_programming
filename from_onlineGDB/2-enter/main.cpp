#include <iostream>
using namespace std;
int main()
{
    int a[25]={4},b,c=0,d,e,f,g,h,i,j,k;
    while(1)
    {
        cout<<" 1:2-10;2:10-2";
        cin>>b;
        if(b==2)
        {
            cin>>b;
            c=0;
            while(b!=0)
            {
                if(b%2==1)
                {
                    a[c]=1;
                }
                else
                {
                    a[c]=0;
                }
                b=b/2;
                c++;
            }
            for(c=24;c>=0;c--)
            {
                if(a[c]!=4)
                {
                    cout<<a[c];
                }
            }
        }
        else
        {
            scanf("%d%d%d%d%d%d%d%d",&d,&e,&f,&g,&h,&i,&j,&k);
            
            cout<<c=d*2*2*2*2*2*2*2+e*2*2*2*2*2*2+f*2*2*2*2*2+g*2*2*2*2+h*2*2*2+i*2*2+j*2+k;;
            
        }
    }
    return 0;

}

//十=>二進位
