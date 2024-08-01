//沒過
#include <bits/stdc++.h>
using namespace std;

#define n 8000
#define m 10000
// #define int long long int

vector<vector<int>> lines(n);
vector<bool> visited(n, false);

queue<int> q;

long long int N, M, a, b;
bool can_visit = false;

void traversal() {
    if (q.empty()) 
        return;
    if (can_visit) 
        return;
    long long int node = q.front();
    q.pop();

    // cout << "queue_front:" << node << endl;

    if (node == b) {
        can_visit = true;
        return;
    }

    for (long long int i = 0; i < lines[node].size(); i++) {
        long long int neighbor = lines[node][i];
        if (!visited[neighbor]) {
            q.push(neighbor);
            visited[neighbor] = true;
        }
    }

    traversal(); // 遞迴調用處理下一個節點
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);   
    while(cin >> N >> M)
    {
        for (long long int i = 0; i < M; i++) {
            cin >> a >> b;
            lines[a].push_back(b);
        }
        cin >> a >> b;

        visited[a] = true;
        q.push(a);

        traversal();

        if (can_visit) {
            printf("Yes!!!\n");
        } else {
            printf("No!!!\n");
        }
    }
}
