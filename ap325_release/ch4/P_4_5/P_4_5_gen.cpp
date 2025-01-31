#include <bits/stdc++.h>
using namespace std;
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}
void one(int n, int ifw) {
    printf("%d\n",n);
    for (int i=0;i<n;i++) {
        printf("%d%c",rand()%1000+1, " \n"[i==n-1]);
    }
    for (int i=0;i<n;i++) {
        int w=(ifw)? rand()%1000: 1;
        printf("%d%c",w, " \n"[i==n-1]);
    }
    return;
}

int main() {
    int n, i, j;
	char infile[30]="P_4_5_0.in";
	srand(5817);

    for (i=1;i<6;i++) {
        infile[6]=i+'0';
        freopen(infile,"w",stdout);
        n=1e5-rand()%1000;
        one(n, i>2);
    }
    return 0;

}
