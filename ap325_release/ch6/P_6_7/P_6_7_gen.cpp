#include <cstdio>
#include <algorithm>
#include <vector>
#include<assert.h>
using namespace std;
#define R 10000
int ran30(int n) {
#if RAND_MAX < 40000
    return ((rand()<<15)|rand())%n;
#else
    return rand()%n;
#endif
}

void one(int n) {
    int i,m=n-rand()%20;
    char s1[510], s2[510];
    for (i=0;i<n;i++) s1[i]='a'+rand()%26;
    s1[n]='\0';
    i=0;
    for (int j=0;j<m;j++) {
        int t=rand()%3;
        if (i>n-3 || t==0) s2[j]=s1[i++];
        else if (t<=2) s2[j]='a'+rand()%26;
        else s2[j]=s1[i+=rand()%3];
    }
    s2[m]='\0';
    printf("%s\n%s\n",s1, s2);
    return;
}

int main() {
    int i,n,m;
	char infile[30]="P_6_7_0.in";
	srand(58111);
for (i=1;i<6;i++) {
    sprintf(infile+6,"%d.in",i);
	freopen(infile,"w",stdout);
	one(i*100);
}
	return 0;
}
