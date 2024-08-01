#include<iostream>
#include <algorithm>

#define size 10000

using namespace std;

struct tree
{
  
  int last=1;
  int sum;
};

struct child
{
    char letter;
    int f;
    char code[1000]={};
    int first_of_code=0;
};

bool cmp(child x,child y)
{
    return x.f>y.f;
}

int main()
{
    while(100)
    {
        char text[10000]={};
        char characters[size]={};
        int number=0;
        tree main;
        gets(text);
        for(int i = 0;i<size;i++)
        {
            
            if(text[i]=='\0')
            {
                number=i;
                break;
                
            }
            if(i==0)
            {
                characters[0]=text[0];
                continue;
            }
            for(int j = 0;j<size;j++)
            {
                if(characters[j]=='\0')
                {
                    break;
                }
                if(characters[j]==text[i])
                {
                    break;
                }
                if(characters[j+1]=='\0')
                {
                    characters[j+1]=text[i];
                }
            }
            //cout<<"meow"<<endl;
        }
        child al[300];
        
        for(int i = 0;i<number;i++)
        {
            //cout<<"cow"<<endl;
            al[i].letter=characters[i];
            for(int j = 0;j<size;j ++)
            {
                if(text[j]=='\0')
                {
                    break;
                }
                if(text[j]==al[i].letter)
                {
                    al[i].f++;
                    
                }
            }
        }
        //cout<<"sere"<<endl;
        sort(al,al+300,cmp);
        
        /*for(int i=0;i<number;i++)
        {
            cout<<al[i].letter<<" "<<al[i].f<<endl;
        }*/
        al[0].code[0]=0;
        al[1].code[0]=1;
        al[1].first_of_code=al[0].first_of_code=1;
        main.sum=al[0].f+al[1].f;
        
        for(int i=2;i<number;i++)
        {
            //cout<<"test"<<endl;
            if(al[i].f==0)
            {
                break;
            }
            if(al[i].f>main.sum)
            {
                al[i].code[0]=1;
                for(int j=0;j<=main.last;j++)
                {
                    al[j].code[al[j].first_of_code]=0;
                    al[j].first_of_code++;
                }
            }
            else
            {
                al[i].code[0]=1;
                for(int j=0;j<=main.last;j++)
                {
                    al[j].code[al[j].first_of_code]=1;
                    al[j].first_of_code++;
                }
            }
            main.last++;    
            main.sum+=al[i].f;
        }
        for(int i=0;i<=main.last;i++)
        {
            cout<<al[i].letter<<" huffmancode: ";
            cout<<endl<<main.last<<endl;
            for(int j=0;j<=main.last;j++)
            {
                cout<<al[i].code[j];
            }
            cout<<"   times: "<<al[i].f<<endl;
        }
        /*for(int i=0;i<=main.last;i++)
        {
            cout<<al[i].letter<<" huffmancode: ";
            for(int j=al[i].first_of_code-1;j>=0;j++)
            {
                cout<<al[i].code[j];
            }
            cout<<"   times: "<<al[i].f<<endl;
        }*/
    }
} 


