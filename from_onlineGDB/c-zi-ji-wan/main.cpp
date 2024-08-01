#include<iostream>

#include<stdio.h>
using namespace std;
char puzzle[100][100]=
    {
    {"    ***"},
    {"    *@*"},
    {"    *#*"},
    {"***** *****"},
    {"*@  #+ # @*"},
    {"**** ******"},
    {"   *#*"},
    {"   *@*"},
    {"   ***"}};
void yee()
{
    int a=0,b=0;
    for( a=0 ; a<11 ; a++ )
    {
        cout<<endl;
        for( b=0 ; b<20 ; b++ )
        {
          cout<<puzzle[a][b];
        }   
    }
}
int main()
{
    int a,b,y=4,x=5,p=0;//a和b負責印地圖x是橫的,橫的是後面,p是分數
    char e;//wasd
    cout<<"按wasd移動以遊玩推箱子(@是目標,#是箱子,+是你,*是牆壁)"<<endl;
    yee();
    while(p!=4)
    {
      cin>>e;
      //e=getch();
      if(e=='w')
      {
        if(puzzle[y-1][x]==' ')
        {
          y--;
          puzzle[y+1][x]=' ';
          puzzle[y][x]='+';
          
        }
        else if(puzzle[y-1][x]=='#')
        {
          if(puzzle[y-2][x]==' ')
          {
            y--;
            puzzle[y+1][x]=' ';
            puzzle[y][x]='+';
            puzzle[y-1][x]='#';
          }
          else if(puzzle[y-2][x]=='@')
          {
            y--;
            puzzle[y+1][x]=' ';
            puzzle[y][x]='+';
            puzzle[y-1][x]='$';
            p++;
          }
     

        }
      }
      if(e=='s')
      {
        if(puzzle[y+1][x]==' ')
        {
          y++;
          puzzle[y-1][x]=' ';
          puzzle[y][x]='+';
        }
        else if(puzzle[y+1][x]=='#')
        {
          if(puzzle[y+2][x]==' ')
          {
            y++;
            puzzle[y-1][x]=' ';
            puzzle[y][x]='+';
            puzzle[y+1][x]='#';
          }
          else if(puzzle[y+2][x]=='@')
          {
            y++;
            puzzle[y-1][x]=' ';
            puzzle[y][x]='+';
            puzzle[y+1][x]='$';
            p++;
          }
        }
      }
      if(e=='a')
      {
        if(puzzle[y][x-1]==' ')
        {
          x--;
          puzzle[y][x+1]=' ';
          puzzle[y][x]='+';
          
        }
        else if(puzzle[y][x-1]=='#')
        {
          if(puzzle[y][x-2]==' ')
          {
            x--;
            puzzle[y][x+1]=' ';
            puzzle[y][x]='+';
            puzzle[y][x-1]='#';
          }
          else if(puzzle[y][x-2]=='@')
          {
            x--;
            puzzle[y][x+1]=' ';
            puzzle[y][x]='+';
            puzzle[y][x-1]='$';
            p++;
          }
     

        }
      }
      if(e=='d')
      {
        if(puzzle[y][x+1]==' ')
        {
          x++;
          puzzle[y][x-1]=' ';
          puzzle[y][x]='+';
        }
        else if(puzzle[y][x+1]=='#')
        {
          if(puzzle[y][x+2]==' ')
          {
            x++;
            puzzle[y][x-1]=' ';
            puzzle[y][x]='+';
            puzzle[y][x+1]='#';
          }
          else if(puzzle[y][x+2]=='@')
          {
            x++;
            puzzle[y][x-1]=' ';
            puzzle[y][x]='+';
            puzzle[y][x+1]='$';
            p++;
          }
        }
      }
      yee();
    }
    if(p==4)
    {
        cout<<"恭喜過關!!!!"<<endl;
    }

}





