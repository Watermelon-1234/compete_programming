#include <bits/stdc++.h>
using namespace std;
#define N 5

int main() {
    int p[N]={5, 1, 8, 3, 9};
    int i=lower_bound(p, p+5, 2)-p;
    printf("%d\n", i);
    return 0;
}
