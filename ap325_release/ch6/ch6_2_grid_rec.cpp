//ch6 grid, recursion
#include <cstdio>
long long grid(int m, int n) {
    if (m==1 || n==1) return 1;
    return grid(m, n-1)+grid(m-1, n);
}
int main() {
    int m,n;
    scanf("%d%d", &m, &n);
    printf("%lld\n", grid(m,n));
    return 0;
}
