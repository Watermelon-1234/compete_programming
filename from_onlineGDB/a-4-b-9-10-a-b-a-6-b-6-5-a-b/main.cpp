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
    float a,b;
    for(a=1;a<=1000;a++)
    {
        for(b=1;b<=1000;b++)
        {
            
            if((a+4)*(b*9/10)==a*b||(a-6)*b*6/5==a*b)
            {
                cout<<"a="<<a<</*"    b="<<b<<*/endl;
                /*printf("((%d+4)*(%d*9/10)==%d*%d||(%d-6)*%d*6/5==%d*%d)",a,b,a,b,a,b,a,b);*/
                cout<<endl;
            }
            
        }
    }
    return 0;
}
