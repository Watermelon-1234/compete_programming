// ch3_4 STL stack, test data at ch3_1.in
#include <bits/stdc++.h>
using namespace std;
#define N 1000
int main() {
    stack<int> S;
    int n, t;
    char cmd[10];
    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        scanf("%s", cmd);
        if (strcmp(cmd,"push")==0) {
            scanf("%d", &t);
            S.push(t); // push(t)
        }
        else if (strcmp(cmd,"pop")==0) {
            if (S.empty()) printf("empty\n");
            else {
                t=S.top();
                S.pop();
                printf("%d\n",t);
            }
        }
    }
    return 0;
}
