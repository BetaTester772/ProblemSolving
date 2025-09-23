#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int M, N;
    cin >> M >> N;

    queue<pair<pair<int, int>, int> > q; // (x, y), day


    vector<vector<int> > arr(N, vector<int>(M));
    vector<vector<bool> > visited(N, vector<bool>(M, false));
    int availableCount = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push({{i, j}, 0});
                visited[i][j] = true;
            }
            if (arr[i][j] != -1) {
                availableCount++;
            }
        }
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int maxDay = 0;
    int visitedCount = q.size();

    while (q.size()) {
        auto [pos, day] = q.front();
        q.pop();
        maxDay = max(maxDay, day);

        for (int i = 0; i < 4; ++i) {
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny] || arr[nx][ny] == -1)
                continue;

            visited[nx][ny] = true;
            visitedCount++;
            arr[nx][ny] = 1;
            q.push({{nx, ny}, day + 1});
        }
    }


    if (visitedCount != availableCount) {
        cout << -1;
    } else {
        cout << maxDay;
    }
}
