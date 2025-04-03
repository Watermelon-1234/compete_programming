
// demo set
#include <bits/stdc++.h>
using namespace std;
#define N 10
#define P 10

int main() {
    set<int> S; // a set S for storing int
    printf("Insert: ");
    for (int i=0;i<N;i++) {
        int t=rand()%P;
        S.insert(t); // insert an element into S
        printf("%d ",t);
    }
    printf("\nTraversal after insertion: ");
    for (auto it=S.begin(); it!=S.end(); it++) {
        printf("%d ", *it); // iterator as a pointer
    }
    printf("\nAnother traversal: for (int e:S)");
    for (int e: S) { // for each element e in S, do ...
        printf("%d ", e);
    }
    printf("\nClear and re-insert data:\n");
    S.clear(); // clear set t empty
    for (int i=0;i<N;i++)
        S.insert(i*5);
    for (int e: S)
        printf("%d ", e);
    printf("\n");
    // to find if an element in the set
    auto it=S.find(15);
    if (it!=S.end()) // return end() when not found
        printf("find 15 in S\n");
    else printf("15 is not in S\n");
    int x=15;
    printf("After S.erase(15)\n");
    S.erase(x); // erase element of value x
    it=S.find(x);
    if (it!=S.end())
        printf("find %d in S\n",x);
    else printf("%d is not in S\n",x);
    // find lower_bound, the first one >=x
    it=S.lower_bound(x);
    if (it!=S.end())
        printf("lower_bound of %d is %d\n", x, *it);
    else printf("no lower_bound of %d\n",x);
    // find upper_bound, the first one >x
    x=(N-1)*5;
    it=S.upper_bound(x);
    if (it!=S.end())
        printf("upper_bound of %d is %d\n", x, *it);
    else printf("no upper_bound of %d\n",x);

    return 0;
}


