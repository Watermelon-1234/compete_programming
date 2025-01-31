#include <bits/stdc++.h>
using namespace std;

void one(int n, int l, int r) {
    stack<int> S;
    int c;
    char left[4]="([{", right[4]=")]}";
    int er=(rand()%10<r)? l-1-rand()%10:l+1;
    fprintf(stderr,"%d\n",er<l-1);
    for (int i=0;i<l;i++) {
        if (i==er) { // insert error
            if (S.empty()) {
                c=rand()%3;
                printf("%c%c",right[c],left[c]);
                i++;
            }
            else {
                c=(S.top()+rand()%2+1)%3;
                printf("%c",right[c]);
                S.pop();
            }
        }
        else if (i+S.size()>=l && er>=l) break;
        else {
            if (S.empty() || rand()%10<7) {
                c=rand()%3;
                printf("%c",left[c]);
                S.push(c);
            }
            else {
                printf("%c", right[S.top()]);
                S.pop();
            }

        }
    }
    while (!S.empty()) {
        printf("%c",right[S.top()]);
        S.pop();
    }
    printf("\n");
    return;
}

int main() {
    int n, i, j;
	char infile[30]="P_3_2_0.in";
	srand(5817);

    for (i=1;i<6;i++) {
        infile[6]=i+'0';
        freopen(infile,"w",stdout);
        n=5+3*i;
        int L=i*20, r=3+rand()%7;
        for (j=0;j<n;j++)
            one(n,L,r);
    }

 return 0;

}
