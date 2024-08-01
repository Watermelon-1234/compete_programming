#include <iostream>

using namespace std;

int main()
{
    while(1){
        float input, sum=0;
        for(int i=0;i<5;i++)
        {
            cin>>input;
            if(input>60)
            {
                input=60+(input-60)*0.7;
            }
            cout<<input<<endl;
            sum+=input;
            
        }
        cout<<sum<<endl;
        cout<<"----------沒用啦 不要算啦---------------"<<endl;
    }
}

