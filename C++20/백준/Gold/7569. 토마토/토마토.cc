#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int M, N, H;
    cin >> M >> N >> H;

    queue<pair<tuple<int, int, int>, int> > q; // (x, y, z), day

    vector<vector<vector<int> > > arr(N, vector<vector<int> >(M, vector<int>(H, -1)));
    vector<vector<vector<bool> > > visited(N, vector<vector<bool> >(M, vector<bool>(H, false)));
    int availableCount = 0;
    for (int h = 0; h < H; ++h) {
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                cin >> arr[n][m][h];
                if (arr[n][m][h] == 1) {
                    q.push(make_pair(make_tuple(n, m, h), 0));
                    visited[n][m][h] = true;
                } else if (arr[n][m][h] == 0) {
                    availableCount++;
                }
            }
        }
    }

    int dx[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};

    int maxDay = 0;
    int visitedCount = 0;

    while (!q.empty()) {
        auto [pos, day] = q.front();
        q.pop();
        maxDay = max(maxDay, day);

        for (int i = 0; i < 6; ++i) {
            int nx = std::get<0>(pos) + dx[i];
            int ny = std::get<1>(pos) + dy[i];
            int nz = std::get<2>(pos) + dz[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H || visited[nx][ny][nz] || arr[nx][ny][nz] ==
                -1)
                continue;

            visited[nx][ny][nz] = true;
            visitedCount++;
            arr[nx][ny][nz] = 1;
            q.push(make_pair(make_tuple(nx, ny, nz), day + 1));
        }
    }

    if (visitedCount != availableCount) {
        cout << -1;
    } else {
        cout << maxDay;
    }
}
