#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int i, int j, vector<vector<int> > &A, vector<vector<bool> > &visited) {
    if (i < 0 || i >= A.size() || j < 0 || j >= A.size() || visited[i][j] || A[i][j] == 0) {
        return 0;
    }

    visited[i][j] = true;
    int count = 1;

    count += dfs(i + 1, j, A, visited);
    count += dfs(i - 1, j, A, visited);
    count += dfs(i, j + 1, A, visited);
    count += dfs(i, j - 1, A, visited);

    return count;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<int> > A(N, vector<int>(N));
    vector<vector<bool> > visited(N, vector<bool>(N, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char c;
            cin >> c;
            A[i][j] = c - '0';
        }
    }

    vector<int> results;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (A[i][j] == 1 && !visited[i][j]) {
                int size = dfs(i, j, A, visited);
                results.push_back(size);
            }
        }
    }

    sort(results.begin(), results.end());
    cout << results.size() << "\n";
    for (int i: results) {
        cout << i << "\n";
    }
}
