#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > grid;
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    grid.resize(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int> > dist(N + 1, vector<int>(N + 1, INT_MAX));
    dist[1][1] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > pq;
    pq.push({0, 1, 1});
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    while (!pq.empty()) {
        auto [d, x, y] = pq.top();
        pq.pop();
        if (d > dist[x][y]) continue;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            int nd = max(d, abs(grid[x][y] - grid[nx][ny]));
            if (nd < dist[nx][ny]) {
                dist[nx][ny] = nd;
                pq.push({nd, nx, ny});
            }
        }
    }
    cout << dist[N][N];
}
