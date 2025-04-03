/* LIS, unweighted strictly increasing
sweeping on increasing x;
last[i] is the smallest of length i
*/

#include<bits/stdc++.h>
using namespace std;

#define N 500010
//#define SMALL
//#define DEBUG
#define CHECK

typedef long long LL;
vector<int> last;
vector<int>::iterator it;
int n,maxleng;
vector<int> in;

int solve() {
    int i,t;
    int ans;
    last.clear();
    in.clear();
    //last.push_back(-1);  assume positive input
    for (i=0;i<n;i++) {
        scanf("%d",&t);
        in.push_back(t);
        it = lower_bound(last.begin(),last.end(),t);
        if (it==last.end()) last.push_back(t);
        else *it=t;
    }
    //for (it=last.begin();it!=last.end();it++) printf("%d ",*it); printf("\n");
    printf("%d\n",last.size());
}

void verify() {
    int i,j;
    last.clear();
    for (auto &x : in) {
        bool found=false;
        for (auto &y: last) {
            if (y>=x) {
                y=x;
                found=true;
                break;
            }
        }
        if (!found) last.push_back(x);
    }
    cout<<"*"<<last.size()<<endl;

}


int main() {
    int i,j,m,k,tcase;
	freopen("lis1.in","r",stdin);
	freopen("lis1.out","w",stdout);
    scanf("%d",&tcase);
	while (tcase--) {
		scanf("%d",&n);// printf("n=%d\n",n);//assert(n<=100000);
        solve();
//        if (n<500000) verify();
//return 0;
	}
    return 0;
}
