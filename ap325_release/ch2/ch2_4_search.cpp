#include <bits/stdc++.h>
using namespace std;
#define N 10
// binary search x between a[left..right]
int bsearch(int a[], int left, int right, int x) {
    while (left <=right) {
        int mid=(left+right)/2;
        if (a[mid]==x) return mid;
        if (a[mid]<x) left = mid+1;
        else right = mid-1;
    }
    return -1;
}

int main() {
    int p[N];
    int n=10;
    for (int i=0;i<n;i++)
        p[i]=rand()%100;
    sort(p, p+n);
    for (int i=0;i<n;i++) printf("%d ",p[i]);
    printf("\n");

    printf("search %d => return %d\n",p[7], bsearch(p,0,n-1,p[7]));
    int t=rand()%100;
    printf("search %d => return %d\n",t, bsearch(p,0,n-1,t));

    return 0;
}
