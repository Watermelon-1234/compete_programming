//請填補以下缺漏的程式碼：
#include <iostream>
using namespace std;

double discount(double a1, double a2){
    if(a1 == a2)
    {
        return (0.5)*(a1);
    }
    else
    {
        return a2;
    }
}
int main(){
    double p1, p2;
    cout << "Original price:" << endl;
    cin >> p1 >> p2;
    p2 = discount(p1, p2);
    cout << "Price after discount:" << endl;
    cout << p1 << " " << p2 << endl;
    return 0;
}
 