#include <cstdio>

int main() {
    int coin[4]={1,5,10,50};
    int m,n;
    scanf("%d",&m);
    for (int i=0;i<m;i++) {
        scanf("%d", &n); // input money
        int num=0; // num of coins
        for (int j=3; j>=0 && n>0; j--) { // large to small
            num += n/coin[j]; // num of coin[j]
            n %= coin[j]; // remaining
        }
        printf("%d\n",num);
    }
    return 0;
}
