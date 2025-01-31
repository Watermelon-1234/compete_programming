// p-5-3 merge_sort
#include <bits/stdc++.h>
using namespace std;

// [le, ri)
void merge_sort(int A[], int le, int ri) {
    if (le+1 >= ri) return; // terminal case
    int m = (le+ri)/2;
    merge_sort(A, le, m); // recursively sort left part
    merge_sort(A, m, ri); // recursively sort right part
    // merge the two sorted lists
    int temp[ri-le], i=le, j=m, k=0;
    while (i<m && j<ri) {
        if (A[i] <= A[j])
            temp[k++] = A[i++];
        else temp[k++] = A[j++];
    }
    // copy remaining
    while (i<m)
        temp[k++] = A[i++];
    while (j<ri)
        temp[k++] = A[j++];
    // copy back to A
    for (k=0, i=le; i<ri; k++, i++)
        A[i] = temp[k];
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
