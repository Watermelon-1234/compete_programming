// demo lower_bound for int array
// binary search the first >=x
#include <bits/stdc++.h>
using namespace std;
#define N 5

int main() {
    int p[N]={5, 1, 8, 3, 9};
    int n=5;
    sort(p, p+n);
    for (int i=0;i<n;i++) printf("%d ",p[i]);
    printf("\n");
    for (int i=0;i<5;i++) {
        int t=i*3;
        // search [first=p, last=p+n) to find the first >=t
        int ndx=lower_bound(p, p+n, t) - p;
        if (ndx<n)
            printf("The first >=%d is at [%d]\n",t, ndx);
        else // return the last address if not found
            printf("No one >=%d\n",t);
    }
    // for vector
    vector<int> v(p, p+n); // copy p to vector v
    for (int i=0;i<5;i++) {
        int t=i*3;
        int ndx=lower_bound(v.begin(), v.end(), t) - v.begin();
        if (ndx<n)
            printf("The first >=%d is at [%d]\n",t, ndx);
        else // return v.end() if not found
            printf("No one >=%d\n",t);
    }

    return 0;
}
