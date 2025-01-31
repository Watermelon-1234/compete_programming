#include <bits/stdc++.h>
using namespace std;
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}
void one(int n) {
    int i;
    printf("%d\n",n);
    for (i=1;i<n;i++) printf("%d ",ran30(1e9)+1);
    printf("%d\n",ran30(1e9)+1);
}


int main() {
    int n, i, j;
	char infile[30]="P_4_12_0.in";
	srand(5817);

    for (i=1;i<6;i++) {
        infile[7]=i+'0';
        freopen(infile,"w",stdout);
        one(1e5-rand()%1000);
    }
	return 0;
}
