//ch6 stair, top-down DP
#include <cstdio>
long long F[100]={0}; // memo, 0 if not computed
long long stair(int n) {
    // if (n<3) return n; not necessary
    if (F[n]>0) return F[n]; // check memo
    F[n] = stair(n-1)+stair(n-2); // record to memo
    return F[n];
}
int main() {
    int n;
    scanf("%d", &n);
    F[1]=1, F[2]=2;
    printf("%lld\n", stair(n));
    return 0;
}
