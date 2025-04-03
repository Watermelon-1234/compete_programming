// P_3_9, use map, to check answer
#include<bits/stdc++.h>
using namespace std;
#define N 200010
int seq[N];
unordered_map<int,int> M;
void ins_c(int c) {
    auto it=M.find(c);
    if (it==M.end()) M[c]=1;
    else it->second ++;
    return;
}
void del_c(int c) {
    auto it=M.find(c);
    if (it==M.end()) fprintf(stderr,"error");
    else {
        it->second --;
        if (it->second==0) M.erase(it);
    }
    return;
}

int main() {
    int n,L,i;
    scanf("%d%d",&n,&L);
    int n_color=0;
    for (i=0;i<n;i++)
        scanf("%d",&seq[i]);
    for (i=0;i<L;i++)
        ins_c(seq[i]);
    int ans=(int)M.size(), left;
    // sliding window, seq[i] in, seq[left] out
    for (left=0,i=L; i<n; i++,left++) {
        ins_c(seq[i]);
        del_c(seq[left]);
        ans=max(ans,(int)M.size());
    }
    printf("%d\n",ans);
    return 0;
}
