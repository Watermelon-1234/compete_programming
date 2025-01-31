#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N;
    while (cin >> N) {
        if (N == 0) break;

        vector<int> data(N);
        for (int i = 0; i < N; i++)
            cin >> data[i];

        int dp[N][2]; // dp[i][0] 銝嚗p[i][1] ���
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        dp[0][1] = data[0];
        for (int i = 1; i < N; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + data[i];
        }

        cout << max(dp[N-1][0], dp[N-1][1]) << endl;
    }

    return 0;
}
