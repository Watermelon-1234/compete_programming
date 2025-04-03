#include <bits/stdc++.h>
using namespace std;
#define N 10
void show(int a[], int n) {
    for (int i=0;i<n-1;i++)
        printf("%3d ",a[i]);
    printf("%3d\n",a[n-1]);
    return;
}

bool cmp1(int s, int t) {
    return s>t;
}
struct point {
    int x,y;
};
bool cmp2(point &s, point &t) {
    return s.x < t.x;
}
bool cmp3(point &s, point &t) {
    return s.y > t.y;
}
bool cmp4(point &s, point &t) {
    return s.x+s.y < t.x+t.y;
}
void showp(point a[], int n) {
    for (int i=0;i<n-1;i++)
        printf("(%2d, %2d) ",a[i].x, a[i].y);
    printf("(%2d, %2d)\n",a[n-1].x, a[n-1].y);
    return;
}
int main() {
    int a[N], n=10;
    for (int i=0;i<n;i++) a[i]=rand()%100;
    show(a,n);
    printf("from large to small\n");
    sort(a, a+n, cmp1);
    show(a,n);

    printf("Using greater\n");
    sort(a, a+n, greater<int>());
    show(a,n);

    point p[N];
    for (int i=0;i<n;i++)
        p[i].x=rand()%100, p[i].y=rand()%100;
    printf("%d points on the plane\n");
    showp(p,n);

    printf("sorted for x from small to large\n");
    sort(p, p+n, cmp2);
    showp(p,n);
    printf("sorted for y from large to small\n");
    sort(p, p+n, cmp3);
    showp(p,n);
    printf("sorted for x+y from small to large\n");
    sort(p, p+n, cmp4);
    showp(p,n);
    return 0;
}
