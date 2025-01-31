/* p_2_11
Brute force method
*/

#include<bits/stdc++.h>
using namespace std;
#define N 200010
int psum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t,v;
    cin>>n>>t;
    int ans=0;
    psum[0]=0;
    for (int i=1;i<=n;i++) {
        cin>>v;
        psum[i]=psum[i-1]+v;
        int best=psum[i], target=psum[i]-t;
        for (int j=0;j<i;j++) {
            if (psum[j]>=target)
                best=min(best,psum[j]);
        }
        ans=max(ans,psum[i]-best);
    }
    cout<<ans<<endl;
    return 0;
}
