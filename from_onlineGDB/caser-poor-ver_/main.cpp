#include<iostream>
#include<string>
using namespace std;


int main()
{
    string fuck;
    int input;
    while(1)
    {
        cout<<"<凱薩->改> 加密工具"<<endl<<"輸入1加密"<<endl<<"輸入二解碼"<<endl<<endl;
        cin>>input;
        switch(input)
        {
            case 1:
                cout<<"輸入位移量"<<endl;
                cin>>input;
                cout<<"輸入密文"<<endl;
                cin>>fuck;
                char fucki=fuck[1];
                for(int i = 0; i < fuck.length(); i++) 
                {
                    if(i=fuck.length()-1)
                        fuck[i]+=(fucki-input);
                    else
                    {
                        fuck[i]+=(int(fuck[i])-input);
                    }
                }
                cout<<fuck;
                break;
        }
        cout<<endl;
    }
}