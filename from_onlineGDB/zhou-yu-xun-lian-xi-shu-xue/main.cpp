#include <iostream>
#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */
using namespace std;
int main()
{
  /* 固定亂數種子 */
  srand( time(NULL) );
  /* 產生亂數 */
  int score=0;
  while(score!=10||score>0)
  {
    int c;
    if(rand()%2==1)
    {
        int a=(rand()%30)+1;
        int b=(rand()%a)+1;
        printf("%d-%d=?\n",a,b);
        cin>>c;
        if(c==a-b)
        {
            score++;
            cout<<"答對了~ 分數是:"<<score<<endl;
        }
        else{
            score--;
            cout<<"答對了~ "<<"正確答案是:"<<a-b<<" 分數是:"<<score<<endl;
        }
    }
    else
    {
        int a=(rand()%100)+1;
        int b=(rand()%a)+1;
        printf("%d+%d=?\n",a,b);
        cin>>c;
        if(c==a+b)
        {
            score++;
            cout<<"答對了~ 分數是:"<<score<<endl;
        }
        else{
            score--;
            cout<<"答錯了~ "<<"正確答案是:"<<a+b<<"  分數是:"<<score<<endl;
        }
    }
  }
  if(score==10)
  {
      cout<<"恭喜過關"<<endl;
  }
  else{
      cout<<"失敗了"<<endl;
  }
  return 0;
}