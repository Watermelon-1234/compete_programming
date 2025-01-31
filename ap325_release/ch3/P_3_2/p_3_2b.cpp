// p3-2 parenthesis matching, no STL
#include <bits/stdc++.h>

int main() {
  char in[210], ch[7]="([{)]}";
  int S[210], top; // stack
  while (scanf("%s",in)!=EOF) {
    top=-1; // clear stack
    int len=strlen(in);
    assert(len<=150);
    bool error=false;
    for (int i=0;i<len;i++) {
        int k=strchr(ch,in[i])-ch;
        //or using: for (k=0; k<6 && ch[k]!=in[i]; k++);
        assert(k<6); // no invalid char
        if (k<3) // left
            S[++top]=k; // push
        else {
            if (top<0 || k!=S[top]+3) { //mismatch
                error=true;
                break;
            }
            top--; // pop
        }
    }
    if (top>=0) error=true;
    printf((error)?"no\n":"yes\n");
  }
  return 0;
}

