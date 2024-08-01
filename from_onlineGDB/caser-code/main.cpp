/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<cmath>

#define size 100000
using namespace std;

int main()
{
    int input;
    float alphabat,e,a;
    char text[size]={},temp;
    while(1)
    {
        cout<<"加密:1 /解密:2 /其他退出(只接受英文字母,數字)/KEYIN時以'#'當作結尾"<<endl;
        cin>>input;
        if(input==1)
        {
            cout<<"輸入金鑰(>0)再輸入明文"<<endl;
            cin>>input;
            while(cin>>text)
            {
                for(int i = 0;i<size;i++)
                {
                    if(text[i]=='\0')
                    {
                        break;
                    }
                    else
                    {
                        if(text[i]>='0'&&text[i]<='9')
                        {
                            text[i]+=input;
                            while(text[i]>'9')
                            {
                                text[i]-=10;
                            }
                        }
                        else if(text[i]>='A'&&text[i]<='Z')
                        {
                            text[i]+=input;
                            while(text[i]>'Z')
                            {
                                text[i]-=26;
                            }
                        }
                        else if(text[i]>='a'&&text[i]<='z')
                        {
                            
                            if((int(text[i])+input%26)>127)
                            {
                                text[i]+=((input%26)-26);
                            }
                            else
                            {
                                text[i]+=(input%26);
                            }
                            
                            
                            while(text[i]>'z')
                            {
                                text[i]-=26;
                                
                            }//cout<<int(text[i]);
                        }
                        else if(text[i]=='#')
                        {
                            cout<<'#';
                            goto end;
                        }
                        cout<<text[i];
                    }
                }
                for(int i=0;i<=size;i++)
                {
                    text[i]='\0';
                }
                cout<<" ";
            }cout<<endl;
        }
        else if(input==2)
        {
            cout<<"輸入密文"<<endl;
            gets(text);
            cin.getline(text,size);
            
            for(int j=0;j<26;j++)
            {
                for(int i =0;i<size;i++)
                {
                    if(text[i]>='0'&&text[i]<='9')
                    {
                        
                        //cout<<"j="<<j<<endl;
                        text[i]+=1;
                        while(text[i]>'9')
                        {
                            text[i]-=10;
                            
                        }//cout<<int(text[i]);
                    }
                    else if(text[i]>='A'&&text[i]<='Z')
                    {
                        
                        if((int(text[i])+1)>127)
                        {
                            text[i]+=((1)-26);
                        }
                        else
                        {
                            text[i]+=(1);
                        }
                        
                        
                        while(text[i]>'Z')
                        {
                            text[i]-=26;
                            
                        }//cout<<int(text[i]);
                    }
                    else if(text[i]>='a'&&text[i]<='z')
                    {
                        
                        if((int(text[i])+1)>127)
                        {
                            text[i]+=((1)-26);
                        }
                        else
                        {
                            text[i]+=(1);
                        }
                        
                        
                        while(text[i]>'z')
                        {
                            text[i]-=26;
                            
                        }//cout<<int(text[i]);
                    }
                }
                cout<<endl;
                alphabat=0;
                e=0;
                a=0;
                for(int i=0;i<size;i++)
                {
                    if(text[i]!='\0')
                    {
                        cout<<text[i];
                    }
                    if((text[i]>='a'&&text[i]<='z')||(text[i]>='A'&&text[i]<='Z'))
                    {
                        alphabat++;
                        if(text[i]=='a'||text[i]=='A')
                        {
                            a++;
                        }
                        else if(text[i]=='e'||text[i]=='E')
                        {
                            e++;
                        }
                    }
                }cout<<endl;
                float per_a=round(a/alphabat*10);
                float per_b=round(e/alphabat*10);
                //per_a=0.1;
                if(alphabat)
                {
                    if(per_a==1||per_b==1)
                    {
                        if(per_a==1&&per_b==1)
                        {
                            cout<<"可能性:80%";
                        }
                        else
                        {
                            cout<<"可能性:40%";
                        }
                    }
                    else
                    {
                        cout<<"可能性:極低";
                    }
                    //cout<<"機率:a="<<per_a*10<<"%"<<endl<<"e="<<per_b*10<<"%"<<endl;
                }
                cout<<endl;
                cout<<"----------------------------------------------------"<<endl;
            }
            for(int i=0;i<=size;i++)
            {
                text[i]='\0';
            }
        }
        else
        {
            cout<<"say goodpye~"<<endl;
            break;
        }
        end:
        {
            cout<<endl;
        }
        cout<<"***********************************************************"<<endl;

    }

    return 0;
}

