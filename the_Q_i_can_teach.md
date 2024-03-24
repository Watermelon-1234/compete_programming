# 遞迴
*  a024.cpp
# structure
*  a271.cpp

g732:因為數字只有1-500所以只要創a[500]紀錄次數即可
a268:快速冪
```cpp=
long long fast_power(int a,int n)
{
    if(n==0)
        return 1;
    long long res=fast_power(a,n/2);
    if(n%2)return res*res*a;
    return res*res;
}
```