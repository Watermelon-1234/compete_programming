#include <cstdio>
#define N 200010
int p[N];

int main() {
    int i, n, m;
	scanf("%d%d",&n, &m);
	for (i=0; i<n; i++)
        scanf("%d", &p[i]);
	int room=0; // current room
	for (i=0; i<m; i++) {
        int q;
        scanf("%d", &q);
        while (q>0) {
            q -= p[room++];
            if (room==n) room=0; //the next of n-1
        }
	}
	printf("%d\n",room);
    return 0;
}
