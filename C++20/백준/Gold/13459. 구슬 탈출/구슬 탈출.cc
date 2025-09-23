#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char> > board(N, vector<char>(M));
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    vector<vector<vector<vector<bool> > > > visited(
        11, vector<vector<vector<bool> > >(11, vector<vector<bool> >(11, vector<bool>(11, false))));

    int ry, rx, by, bx;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                ry = i;
                rx = j;
            }
            if (board[i][j] == 'B') {
                by = i;
                bx = j;
            }
        }
    }

    queue<tuple<int, int, int, int, int> > q;
    q.push({ry, rx, by, bx, 0});
    visited[ry][rx][by][bx] = true;

    while (!q.empty()) {
        auto [cry, crx, cby, cbx, moves] = q.front();
        q.pop();

        if (moves >= 10) {
            cout << 0;
            return 0;
        }

        for (int d = 0; d < 4; ++d) {
            int nry = cry, nrx = crx, nby = cby, nbx = cbx;

            while (board[nry + dy[d]][nrx + dx[d]] != '#' && board[nry][nrx] != 'O') {
                nry += dy[d];
                nrx += dx[d];
                if (board[nry][nrx] == 'O') break;
            }

            while (board[nby + dy[d]][nbx + dx[d]] != '#' && board[nby][nbx] != 'O') {
                nby += dy[d];
                nbx += dx[d];
                if (board[nby][nbx] == 'O') break;
            }

            if (board[nby][nbx] == 'O') continue;

            if (board[nry][nrx] == 'O') {
                cout << 1;
                return 0;
            }

            if (nry == nby && nrx == nbx) {
                if (d == 0) {
                    // 위
                    if (cry < cby) {
                        nby += 1;
                    } else {
                        nry += 1;
                    }
                } else if (d == 1) {
                    // 아래
                    if (cry > cby) {
                        nby -= 1;
                    } else {
                        nry -= 1;
                    }
                } else if (d == 2) {
                    // 왼쪽
                    if (crx < cbx) {
                        nbx += 1;
                    } else {
                        nrx += 1;
                    }
                } else if (d == 3) {
                    // 오른쪽
                    if (crx > cbx) {
                        nbx -= 1;
                    } else {
                        nrx -= 1;
                    }
                }
            }

            if (!visited[nry][nrx][nby][nbx]) {
                visited[nry][nrx][nby][nbx] = true;
                q.push({nry, nrx, nby, nbx, moves + 1});
            }
        }
    }

    cout << 0;
}
