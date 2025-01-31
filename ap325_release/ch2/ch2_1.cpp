//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
#define N 10


int main() {
    int a[N], n=10;
    for (int i=0;i<n;i++) a[i]=rand()%100;
    for (int i=0;i<n;i++)
        printf("%2d%c",a[i]," \n"[i==n-1]);
    printf("Sort entire array\n");
    sort(a, a+n);
    for (int i=0;i<n;i++)
        printf("%2d%c",a[i]," \n"[i==n-1]);
    printf("Random shuffle\n");
    random_shuffle(a, a+n);
    for (int i=0;i<n;i++)
        printf("%2d%c",a[i]," \n"[i==n-1]);

    printf("Sort a[3..7]\n");
    sort(&a[3], &a[8]);
    for (int i=0;i<n;i++)
        printf("%2d%c",a[i]," \n"[i==n-1]);

    printf("From large to small\n");
    sort(a, a+n, greater<int>());
    for (int i=0;i<n;i++)
        printf("%2d%c",a[i]," \n"[i==n-1]);
    return 0;
}
