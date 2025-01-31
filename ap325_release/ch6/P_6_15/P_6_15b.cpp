// P-6-15 LIS, using STL
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, si;
    scanf("%d",&n);
    vector<int> last;
    for (int i=0; i<n; i++) {
        scanf("%d", &si);
        auto it = lower_bound(last.begin(),last.end(),si);
        if (it==last.end()) last.push_back(si);
        else *it=si;
    }
    printf("%d\n",(int)last.size());
    return 0;
}
