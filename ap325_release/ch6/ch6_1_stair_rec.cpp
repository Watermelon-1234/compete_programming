//ch6 stair, recursion
#include <cstdio>
long long stair(int n) {
    if (n<3) return n;
    return stair(n-1)+stair(n-2);
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", stair(n));
    return 0;
}
