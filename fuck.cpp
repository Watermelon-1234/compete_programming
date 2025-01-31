#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int M, N, q;
vector<vector<int>> grid;
vector<pair<int, int>> bombs;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool canExplode(int r, int c, int radius) {
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    int count = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny]) {
                if (grid[nx][ny] != -1) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    ++count;
                }
            }
        }
    }

    return count >= q;
}

int main() {
    cin >> M >> N >> q;
    grid.resize(M, vector<int>(N));
    bombs.clear();

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] > 0) {
                bombs.push_back({i, j});
            }
        }
    }

    int left = 1, right = 30;
    int result = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        bool found = false;

        for (auto& bomb : bombs) {
            int r = bomb.first;
            int c = bomb.second;
            if (canExplode(r, c, mid)) {
                found = true;
                break;
            }
        }

        if (found) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}
