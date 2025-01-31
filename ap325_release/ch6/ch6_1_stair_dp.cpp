//ch6 stair, dp
#include <cstdio>
int main() {
    long long F[10000];
    int n;
    scanf("%d", &n);
    F[1]=1, F[2]=2;
    for (int i=3;i<=n;i++)
        F[i]=F[i-1]+F[i-2];
    printf("%lld\n", F[n]);
    return 0;
}
