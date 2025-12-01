#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0)
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n"
#define int int64_t
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define rep(i,n) for(int i=0;i<(n);++i)
#define foo(i,a,b) for(int i=(a);i<=(b);++i)
#define oof(i,a,b) for(int i=(a);i>=(b);--i)
#define all(x) begin(x),end(x)
#define btw(a,b,c) ((a)<=(b)&&(b)<=(c))
using namespace std;

// Variadic debug function with variable name printing
template <typename T>
void print_debug(const char* name, T value) {
    cerr << "\e[1;31m" << name << " = " << value;
}

template <typename T, typename... Args>
void print_debug(const char* names, T value, Args... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " = " << value;
    if (comma) cerr << ", ";
    print_debug(comma + 1, args...);
}

template <typename T, typename... Args>
void formatter(const char* names, T value, Args... args) {
    cerr << "\e[1;31m"<< "debug: [" ;
    print_debug(names,value, args...);
    cerr <<  "]"  << "\e[0m\n";
}

#define debug(...) formatter(#__VA_ARGS__, __VA_ARGS__)

// Orange function for range printing
template <typename T>
void orange(T L, T R) {
    cerr << "\e[1;31morange: ";
    for (int f = 0; L != R; ++L) cerr << (f++ ? " " : "") << *L;
    cerr << "\e[0m\n";
}

template <typename T>
T& inpr()
{
    static T tmp;
    cin>>tmp;
    return tmp;
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void split(const std::string& s, std::vector<std::string>& tokens, const std::string& delimiters = " ") {
    std::string::size_type lastPos = s.find_first_not_of(delimiters, 0);
    std::string::size_type pos = s.find_first_of(delimiters, lastPos);
    while (std::string::npos != pos || std::string::npos != lastPos) {
        tokens.push_back(s.substr(lastPos, pos - lastPos));
        lastPos = s.find_first_not_of(delimiters, pos);
        pos = s.find_first_of(delimiters, lastPos);
    }
}

class date{
    public:
        int year, month, day;
        date(int y, int m, int d): year(y), month(m), day(d) {}
        bool isLeapYear() {
            return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        }
        int daysInMonth() {
            static const int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (month == 2 && isLeapYear()) {
                return 29;
            }
            return daysPerMonth[month - 1];
        }
        void addDays(int n) {
            day += n;
            while (day > daysInMonth()) {
                day -= daysInMonth();
                month++;
                if (month > 12) {
                    month = 1;
                    year++;
                }
            }
        }
        void printDate() {
            cout << year << (month < 10 ? "/0" : "/") << month << (day < 10 ? "/0" : "/") << day << "\n";
        }
};

int N, _lcm=1;
vector<int> a;
vector<string> date_array;
string s;

#undef int
int main() {
    #define int int64_t
    fastio;
    cin >> N;
    foo(i, 1, N)
    {
        a.push_back(inpr<int>());
    }
    sort(all(a));
    foo(i, 0, N)
    {
        // debug(_lcm, a[i]);
        if(a[i])
        {
            _lcm = abs(_lcm*a[i])/(gcd(_lcm, a[i]));
        }
    }
    cin >> s;
    split(s, date_array, "/");
    // orange(all(date_array));
    date today(stoi(date_array[0]), stoi(date_array[1]), stoi(date_array[2]));
    today.addDays(_lcm);
    today.printDate();

    return 0;
}