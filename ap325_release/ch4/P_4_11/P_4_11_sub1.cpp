// P-4-11, subtask, table method
#include <stdio.h>

int main() {
	int i,left,right,n;
	int seg[1001]={0},total=0;
	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf("%d%d",&left,&right);
		for (j=left; j<right; j++)
		    seg[j] = 1;
	}
	for (i=0;i<1000;i++)
        total += seg[i];
	printf("%d\n", total);
	return 0;
}



