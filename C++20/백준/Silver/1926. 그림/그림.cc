#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > table;
queue<pair<int, int> > q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    table.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> table[i][j];
        }
    }
    int cnt = 0, max_area = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (table[i][j] == 1) {
                int cur_area = 0;
                q.push({i, j});
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    if (table[x][y] != 1) continue;
                    table[x][y] = 2;
                    cur_area += 1;
                    if (x > 1 && table[x - 1][y] == 1)
                        q.push({x - 1, y});
                    if (x < n && table[x + 1][y] == 1)
                        q.push({x + 1, y});
                    if (y > 1 && table[x][y - 1] == 1)
                        q.push({x, y - 1});
                    if (y < m && table[x][y + 1] == 1)
                        q.push({x, y + 1});
                }
                cnt += 1;
                max_area = max(max_area, cur_area);
            }
        }
    }
    cout << cnt << '\n' << max_area;
}
