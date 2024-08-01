/****************************
這邊是周裕閎自己的函式庫
懶得重打的時候這裡找找
周裕閎你聽到沒有
*****************************/

/***********

數字位數類

*///////////
//這int有幾位
int Nod(int a)//Number of digits
{
    int d;
    while(a>0)
    {
        a/=10;
        d++;
    }
    return d;
}






/************

亂數類

************/
//必要式子
#include <iostream>
#include <stdlib.h> /* 亂數相關函數 */
#include <time.h>   /* 時間相關函數 */
using namespace std;

int main()
{
    srand( time(NULL) );   /* 設定亂數種子 */
}
/********************************************/
//A到B(不包含)
int Rnni(int a,int b ) //Random random number (not including
{
    int c=(rand()%(b-a))+a;
    return c;
}// not yet



