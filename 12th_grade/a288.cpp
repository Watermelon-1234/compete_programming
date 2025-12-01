#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0)
#define int int64_t
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;

int N;
string input;
vector<string> S;
int cur_idx = 0;

int count_paths() {
    int paths = 1; 
    while(cur_idx < S.size() && S[cur_idx] != "ENDPROGRAM") {
        if(S[cur_idx] == "S") {
            cur_idx++;
            continue; 
        }
        else if(S[cur_idx] == "IF") {
            cur_idx++;
            int paths_if = count_paths();   
            int paths_else = count_paths();
            paths *= (paths_if + paths_else);
        }
        else if(S[cur_idx] == "ELSE") {
            cur_idx++; 
            return paths;
        }
        else if(S[cur_idx] == "END_IF") {
            cur_idx++; 
            return paths;
        }
        else {
            cur_idx++;
        }
    }
    return paths;
}

#undef int
int main() {
    #define int int64_t
    fastio;
    cin >> N;
    rep(i,N) {
        S.clear();
        while(cin >> input) {
            S.push_back(input);
            if(input == "ENDPROGRAM") break;
        }
        cur_idx = 0;
        cout << count_paths() << "\n";
    }
    return 0;
}
