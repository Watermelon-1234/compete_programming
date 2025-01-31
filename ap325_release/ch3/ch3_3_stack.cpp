// ch3_3 self-made stack, test data = ch3_1.in
#include <bits/stdc++.h>
#define N 1000
int main() {
    int S[N], top=-1;
    int n, t;
    char cmd[10];
    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        scanf("%s", cmd);
        if (strcmp(cmd,"push")==0) {
            scanf("%d", &t);
            S[++top]=t; // push(t)
        }
        else if (strcmp(cmd,"pop")==0) {
            if (top<0) printf("empty\n");
            else {
                t=S[top--];
                printf("%d\n",t);
            }
        }
    }
    return 0;
}
