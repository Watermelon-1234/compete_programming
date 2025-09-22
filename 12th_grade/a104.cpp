//just a big number = = https://hackmd.io/@xrtzbnHRQn2bgK-IDmEWsQ/SJWK55KKJx


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct BigInt {
    string value; 

    BigInt() : value("0") {}

    BigInt(string s) {
        reverse(s.begin(), s.end());
        value = s;
    }

    BigInt(int num) {
        if (num == 0) {
            value = "0";
        } else {
            while (num > 0) {
                value.push_back('0' + (num % 10));
                num /= 10;
            }
        }
    }

    BigInt operator+(const BigInt& b) const {
        int carry = 0;
        string res; 
        int len1 = value.size(), len2 = b.value.size();
        int maxLen = max(len1, len2);

        for (int i = 0; i < maxLen || carry; ++i) {
            int x = i < len1 ? value[i] - '0' : 0;
            int y = i < len2 ? b.value[i] - '0' : 0;
            int sum = x + y + carry;
            res.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        BigInt ret;
        ret.value = res;  
        return ret;
    }

    BigInt operator*(const BigInt& b) const {
        int len1 = value.size(), len2 = b.value.size();
        vector<int> result(len1 + len2, 0);

        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                result[i + j] += (value[i] - '0') * (b.value[j] - '0');
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] %= 10;
            }
        }

        string resStr;
        int i = result.size() - 1;
        while (i >= 0 && result[i] == 0) --i; 
        if (i == -1) {
            return BigInt("0");
        }
     
        while (i >= 0) {
            resStr.push_back(result[i] + '0');
            --i;
        }
        reverse(resStr.begin(), resStr.end());
        BigInt ret;
        ret.value = resStr; 
        return ret;
    }

    void print() const {
        for (int i = value.size() - 1; i >= 0; --i) {
            cout << value[i];
        }
        cout << endl;
    }
};

int main(){
    int N;
    cin >> N;

    BigInt total("0");  
    BigInt power("1"); 
    BigInt four("4");  

    for (int i = 1; i <= N; ++i) {
        total = total + power;  
        power = power * four;
    }

    total.print();

    return 0;
}
