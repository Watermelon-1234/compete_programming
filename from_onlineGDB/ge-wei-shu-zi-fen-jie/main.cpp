/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>//https://www.csie.ntu.edu.tw/~b98902112/cpp_and_algo/why_learn_coding.html很棒
using namespace std;
int* newArray(int m, int initial = 0) 
{ 
    int *a = new int[m]; 
    for(int i = 0; i < m; i++) {
        a[i] = initial; 
    }
    return a; 
}
int* into(int m,long int in)//m=位數,in==被分解數
{
    for(int i=1;i<=m;i++)
    {
        a[i]=in%10;
        in/=10;
    }
}
viod coutarray(int* arr)
{
    for(int i=1;i<=m;i++)
    {
        
        cout
    }
}
void deleteArray(int* arr) 
{
    delete [] arr; 
}
int main()
{
    long int in;//被分解數
    int x=1;//位數
    int *arr;
    while(x)
    {
        cout<<"它是幾位數?(結束請輸入0)"<<endl;
        cin>>x;
        arr = newArray(x);
        cout<<"請輸入數值"<<endl;
        cin>>in;
        
        if(x==0)
        {
            cout<<"謝謝再聯絡"<<endl;
            break;
        }
    }
    deleteArray(arr);

    return 0;
}

