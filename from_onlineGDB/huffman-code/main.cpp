#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define size 100000
char text[size]={};
char characters[size]={};
int number=0;
int size_alphabat=0;


struct fuck
{
    char alphabat;
    fuck* left;
    fuck* right;
    int times=0;
    bool usin=1;
};
fuck* root=new fuck;
bool cmp(fuck x,fuck y)
{
    return x.times>y.times;
}

void insert_fuck(fuck *&ptr,fuck* aim)
{
    if(ptr)
    {
        if(ptr->left==NULL&&ptr->right==NULL)
        {
            if((ptr->times)>(aim->times))
            {
                ptr->right=aim;
            }
            else//== or <
            {
                ptr->left=aim;
            }
            return;
        }
        else
        {
            insert_fuck(ptr->left,aim);
            insert_fuck(ptr->right,aim);
            cout<<"fuck";
        }
    }
}


void fullprinter(int lv,fuck *ptr)
{

    if(ptr)
    {
        int lvv =lv;
        cout<<"level alphabat ptr left right times"<<endl<<lv<<" "<<ptr->alphabat<<" "<<ptr<<" "<<ptr->left<<" "<<ptr->right<<" "<<ptr->times<<endl;
        fullprinter(lvv+1,ptr->left);
        fullprinter(lvv+1,ptr->right);
    }

}

int main()
{
    while(1)
    {
        gets(text);
        
        
        /*for(int i = 0;i<size;i++)
        {
            if(text[i]=='\0')
            {
                if(i==0)
                {
                    cout<<"sss";
                }
                break;
            }
            
            cout<<text[i]<<" ";
        }*/
        
        for(int i = 0;i<size;i++)
        {
            
            if(text[i]=='\0')
            {
                break;
                number=i;
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
            
        }
        fuck al[100000];
        for(int i = 0;i<number;i++)
        {
            al[i].alphabat=characters[i];
            for(int j = 0;j<size;i++)
            {
                if(text[j]=='\0')
                {
                    break;
                }
                if(text[j]==al[i].alphabat)
                {
                    al[i].times++;
                }
            }
        }
        //size_alphabat
        for(int i=0;i<size;i++)
        {
            if(characters[i]=='\0')
            {
                size_alphabat=i;
            }
        }
        sort(al,al+size_alphabat,cmp);
        
        for(int i=0;i<size_alphabat;i++)
        {
            insert_fuck(root,&al[i]);//run time error
        }
        
        for(int i =0;i<size;i++)
        {
            characters[i]=text[i]='\0';
        }
        cout<<endl<<endl;
        fullprinter(1,root);
        number=0;
        //clear
    }
    return 0;
}


