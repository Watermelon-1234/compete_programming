// P3-8, O(N) using deque
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
int seq[MAXN];
deque<int> max_q, min_q; // index of max and min queue
// put seq[i] from back of max_q
void put_max(int i) {
    // remove useless
    while (!max_q.empty() && seq[max_q.back()]<=seq[i])
        max_q.pop_back();
    max_q.push_back(i);
}
// put seq[i] from back of min_q
void put_min(int i) {
    // remove useless
    while (!min_q.empty() && seq[min_q.back()]>=seq[i])
        min_q.pop_back();
    min_q.push_back(i);
}

int main() {
    int n, L, i,j, max_diff=0;
    scanf("%d%d\n", &n, &L);
    for (i=0; i<n; i++) {
        scanf("%d",&seq[i]);
    }
    put_max(0);
    put_min(0);
    for (i=1; i<n; i++) {
        // put the ith element into max_queue
        if (max_q.front()<=i-L)  // out-of-range
            max_q.pop_front(); // its index
        put_max(i);
        // put the ith element into min_queue
        if (min_q.front()<=i-L)  // out of range
            min_q.pop_front();
        put_min(i);
        // the diff of this subarray
        int diff=seq[max_q.front()]-seq[min_q.front()];
        max_diff=max(max_diff, diff);
    }
    printf("%d\n",max_diff);
    return 0;
}
