// build step table first and then count the number
#include <bits/stdc++.h>
#define ND 20

int main() {
	int i, j, len;
	char n[100];
	long long  step[ND][10], total=0;
    scanf("%s", n);
    len = strlen(n);
    for (i=0; i<len; i++)
        n[i] -= '0';
    // build table, steo[i][j] for i-digits and start with j
    for (j=1; j<10; j++)
        step[1][j] = 1;
    step[1][0] = 0; // 0 is not stepping number
    // step[i][j] =sum(step[i-1][k] for k>=j)
    // or = step[i][j+1] + step[i-1][j], suffix sum
    for (i=2; i<=len; i++) {
        step[i][9] = step[i-1][9];
        for (j=8; j>=0; j--)
            step[i][j] = step[i][j+1] + step[i-1][j];
    }
    // counting
    for (j=0; j<n[0]; j++)
        total += step[len][j];
    for (i=1; i<len; i++) {
        if (n[i] < n[i-1]) break;
        for (j=n[i-1]; j<n[i]; j++)
            total += step[len-i][j];
    }
    if (i == len) total++; // input is a stepping number
    printf("%lld\n", total);
    return 0;
}
