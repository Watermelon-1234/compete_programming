#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
	char infile[30]="P_2_11_0.in";
	srand(5817);

    for (i=1;i<6;i++) {
        infile[7]=i+'0';
        freopen(infile,"w",stdout);
        n=100000-rand()%100;
        printf("%d %d\n",n,n*200+rand()%n);
        for (j=0;j<n-1;j++) printf("%d ",rand()%1000-300);
        printf("%d\n",rand()%1000-300);
    }

 return 0;

}
