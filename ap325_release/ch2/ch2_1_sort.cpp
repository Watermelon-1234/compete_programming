#include <bits/stdc++.h>
using namespace std;
#define N 10
void show(int a[], int n) {
    for (int i=0;i<n-1;i++)
        printf("%3d ",a[i]);
    printf("%3d\n",a[n-1]);
    return;
}

int main() {
    int a[N], n=10;
    for (int i=0;i<n;i++) a[i]=rand()%100;
    show(a,n);
    printf("Sort entire array\n");
    sort(a, a+n);
    show(a,n);

    printf("Random shuffle\n");
    random_shuffle(a, a+n);
    show(a,n);

    printf("Sort a[3..7]\n");
    sort(a+3, a+8);
    show(a,n);
    return 0;
}
