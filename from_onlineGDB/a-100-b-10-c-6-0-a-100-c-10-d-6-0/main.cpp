/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d=0;
    for(a=1;a<=9;a++)
    {
        for(b=0;b<=9;b++)
        {
            for(c=0;c<=9;c++)
            {
                if((a*100+b*10+c)%6==0&&(a*100+c*10+b)%6==0)
                {
                    cout<<"("<<a*100+b*10+c<<","<<a*100+c*10+b<<")"/*<<endl*/;
                    d+=1;
                    
                    }
                }
            }
        }
    }
    cout<<"共"<<d<<"個幸運數"<<endl;
    return 0;
}
