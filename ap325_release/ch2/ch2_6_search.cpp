#include <bits/stdc++.h>
using namespace std;
#define N 10
// binary search the first >=x between a[0..n-1]
int jump_search(int a[], int n, int x) {
    if (a[0]>=x) return 0; // check the first
    int po=0; // the current position, always < x
    for (int jump=n/2; jump>0; jump/=2) { //jump distance
        while (po+jump<n && a[po+jump]<x)
            po += jump;
    }
    return po+1;
}

int main() {
    int p[N];
    int n=10;
    for (int i=0;i<n;i++)
        p[i]=rand()%100;
    sort(p, p+n);
    for (int i=0;i<n;i++) printf("%d ",p[i]);
    printf("\n");
    for (int i=0;i<21;i++) {
        int t=(i-1)*5;
        printf("search %d => return %d\n",t, jump_search(p,n,t));
    }

    return 0;
}
