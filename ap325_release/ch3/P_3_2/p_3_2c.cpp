// p3-2 parenthesis matching, using STL
#include <bits/stdc++.h>
using namespace std;

int main() {
  char in[210], ch[7]="([{)]}";
  while (scanf("%s",in)!=EOF) {
    stack<int> S;
    // fprintf(stderr,"input length=%d\n",strlen(in));
    bool error=false;
    for (int i=0,len=strlen(in);i<len;i++) {
        int sym=strchr(ch,in[i])-ch;
        if (sym>=6) {
            fprintf(stderr,"i=%d, %d, %c",i, sym, in[i]);
            return -1;
        }
        assert(sym>=0 && sym<6);
        if (sym<3) { // left
            S.push(sym);
        }
        else {
            if (S.empty() || sym!=S.top()+3) {//mismatch
                error=true;
                break;
            }
            //match
            S.pop();
        }
    }
    if (!S.empty()) error=true;
    printf((error)?"no\n":"yes\n");
  }
  return 0;
}
