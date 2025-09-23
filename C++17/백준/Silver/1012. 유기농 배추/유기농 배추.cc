#include <iostream>
#include <vector>

using namespace std;

void dfs(int i, int j, vector<vector<int> > &A, vector<vector<bool> > &visited) {
    if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size() || visited[i][j] || A[i][j] == 0) {
        return;
    }

    visited[i][j] = true;

    dfs(i + 1, j, A, visited);
    dfs(i - 1, j, A, visited);
    dfs(i, j + 1, A, visited);
    dfs(i, j - 1, A, visited);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    int T, M, N, K;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        cin >> M >> N >> K;

        vector<vector<int> > A(N, vector<int>(M, 0));
        vector<vector<bool> > visited(N, vector<bool>(M, false));

        for (int i = 0; i < K; ++i) {
            int a, b;
            cin >> a >> b;
            A[b][a] = 1;
        }

        int result = 0;
        for (int i = 0; i < N; ++i && result <= K) {
            for (int j = 0; j < M; ++j && result <= K) {
                if (visited[i][j] == false) {
                    dfs(i, j, A, visited);
                    if (visited[i][j] == true)
                        result++;
                }
            }
        }
        cout << result << endl;
    }
}
