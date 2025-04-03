// p-5-3 merge_sort
#include <bits/stdc++.h>
using namespace std;

// [le, ri)
void merge_sort(int a[], int le, int ri) {
    if (le+1 >= ri) return; // terminal case
    int m = (le+ri)/2;
    merge_sort(a, le, m); // recursively sort left part
    merge_sort(a, m, ri); // recursively sort right part
    // merge the two sorted lists
    int temp[ri-le], j=m, k=0;
    for (int i=le; i<m; i++) {
        while (j<ri && a[j]<a[i])
            temp[k++] = a[j++];
        temp[k++] = a[i];
    }
    // the remaining of right part are already on position
    // copy back to a
    for (k=le; k<j; k++)
        a[k] = temp[k-le];
    return;
}

int main() {
    int a[10]={3, 0, 7, -3, -10, 5, 1, 7, 6, -2};
    merge_sort(a, 0, 10);
    for (int i=0; i<10; i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
