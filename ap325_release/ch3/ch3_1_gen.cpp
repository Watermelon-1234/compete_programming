#include <bits/stdc++.h>
using namespace std;

int main(){
	int i,p=1e9+9;
	char infile[30]="ch3_1.in";
	srand(582);
	freopen(infile, "w", stdout);
	printf("%d\n", 20);
	for (i=0; i<20; i++) {
        if (rand()&1) printf("push %d\n", rand()%10);
        else printf("pop\n");
	}
    return 0;
}
