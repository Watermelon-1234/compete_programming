// P-2-15, repeatedly search range sum in circular array
#include <cstdio>
#define N 500010
int p[N];

int main() {
    int i, n, m;
	scanf("%d%d",&n, &m);
	for (i=0; i<n; i++)
        scanf("%d", &p[i]);
	for (i=1; i<n; i++)
        p[i] += p[i-1];
	int room=0, q, total=p[n-1];
	for (i=0; i<m; i++) {
        scanf("%d", &q);
        if (room != 0) // desired prefix-sum
            q += p[room-1];
        if (q > total) // over the end
            room = 0, q -= total;
        // find the last one < q
        if (p[room] >= q) { // current room is enough
            room =(room+1)%n;
            continue;
        }
        // binary search
        for (int jump=(n-room)/2; jump>0; jump/=2) {
            while (room+jump<n && p[room+jump]<q)
                room += jump;
        }
        room = (room+2)%n; // room+1 is the first >=q
	}
	printf("%d\n",room);
    return 0;
}
