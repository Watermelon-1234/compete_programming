/**
"1 =頭加入元素"
"2=刪除資料"
"3=資料大小"
"4=列印全部"
"5=清除全部"
"6=尋找數字是否在LIST中"
"7=尾加入元素"
"8=更改數值"
 * 
 * 
 * 
 * 
 */
#include <iostream>
using namespace std;
struct link
{
    int data;
    struct link *next;
};
void push_font(int input);
void push_back(int input);
void delet();
void clear();
void size();
void printall();
link *head;
void finder(int input);
void changer(int x,int y);

int main()
{
    head = new link();
    head->next=NULL;
    while(1)
    {
        cout<<"1 =頭加入元素"
        <<endl<<"2=刪除資料"
        <<endl<<"3=資料大小"
        <<endl<<"4=列印全部"
        <<endl<<"5=清除全部"
        <<endl<<"6=尋找數字是否在LIST中"
        <<endl<<"7=尾加入元素"
        <<endl<<"8=更改數值"<<endl;
        int input;
        cin>>input;
        switch (input){
            case 1:
                cout<<"請輸入要加入的數字"<<endl;
                cin>>input;
                push_font(input);
                break;
            case 2:
                cout<<"要刪除哪一個元素?"<<endl;
                delet();
                break;
            case 3:
                size();
                break;
            case 4:
                printall();
                break;
            case 5:
                clear();
                break;
            case 6:
                cout<<"請輸入想要尋找的元素"<<endl;
                cin>>input;
                finder(input);
                break;
            case 7:
                cout<<"請輸入要加入的數字"<<endl;
                cin>>input;
                push_back(input);
                break;
            case 8:
                cout<<"輸入要更改的目標和要更改為的數值"<<endl;
                int x,y;
                cin>>x>>y;
                changer(x,y);
                break;
        }
        for(int i=0;i<5;i++)
        {
            cout<<endl;
        }
        cout<<"______________________________"<<endl;
    }
    
    delete head;
    return 0;
}
void push_font(int input)
{
    link *e = new link();
    e->data=input;
    e->next=head->next;
    head->next=e;
    
}
void push_back(int input)
{
    link *e = new link();
    e->data=input;
    e->next=NULL;
    if(head->next==0)
    {
        head->next=e;//彤前面pushfont
    }
    else
    {
        link *current = head;
        while(current->next!= 0){           
            current = current->next;
        }
        current->next = e;         
    }
}
void clear()
{
    while (head->next != 0) {            
        link *current = head ;
        head = head->next;
        delete current;
        current = 0;
    }
}
void delet()
{
    int input;
    cin>>input;
    link *current = head;
    link *next2;
    while (current->next != 0 ) 
    {            
        next2=current->next;
        if(next2->data==input){
            current->next=next2->next;
            
            
            delete next2;
            cout<<"已完成"<<endl;
            return;
        }
        current=current->next;
    }
    cout<<"FALSE"<<endl;
    return;
    
}
void size()
{
    int size=0;
    if (head->next == 0) {                      
        cout << "List is empty.\n";
    }
    link *current = head;            
    while (current->next != 0) {              
        size++;
        current = current->next;
    }
    cout <<"list 中有 "<<size<<"個"<<endl;
}
void printall()
{

    if (head->next == 0) {                      
        cout << "List is empty.\n";
    }
    else
    {
        cout<<"list 中有: ";
    }
    link *current = head;            
    while (current->next != 0){              
        current = current->next;
        cout << current->data << " ";
        
    }
    cout << endl;
}
void finder(int input)
{
    link *current = head;
    while (current->next != 0 ) 
    {            
        if(current->data==input){
            cout<<"TRUE"<<endl;
            return;
        }
        current=current->next;
    }
    cout<<"FALSE"<<endl;
    return;
}
void changer(int x,int y)
{
    link *current = head;
    while (current->next != 0 ) 
    {            
        if(current->data==x){
            current->data=y;
            cout<<"已完成"<<endl;
            return;
        }
        current=current->next;
    }
    cout<<"沒有這個值"<<endl;
    return;
}



