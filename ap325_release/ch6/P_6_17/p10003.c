#include <stdlib.h>
#include <stdio.h>
int cmp(int *a, int *b) {return *a-*b;}
int main() {
    int x[600][600],n,m,i,j,k,cost,min;
    scanf("%d%d",&n, &m);k=0;
    for (i=0;i<n;i++)
        scanf("%d",&x[0][i]);
    x[0][n]=m;
    qsort(&x[0][0],n,sizeof(int),cmp);
    for (i=n;i>0;i--) x[0][i]-=x[0][i-1]; // length of each segment
    for (i=1;i<=n;i++) {/* row i is the cost of i+1 segment */
        for (j=0;j<=n-i;j++) {
            min=x[0][j]+x[i-1][j+1];
            for (k=2;k<=i;k++) {
                cost=x[k-1][j]+x[i-k][j+k];
                if (cost<min) min=cost;
            }
            for (k=j;k<=j+i;k++) min+=x[0][k];
            x[i][j]=min;
        }
    }
    printf("%d\n",x[n][0]-m);
    return 0;
}

