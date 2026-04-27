#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<bool> > &A, vector<vector<int> > &distance) {
    queue<pair<int, int> > q;

    distance[0][0] = 1;
    q.push({0, 0});
    pair<int, int> u;

    while (q.size()) {
        u = q.front();
        q.pop();
        if (u.first > 0 && A[u.first - 1][u.second] && distance[u.first - 1][u.second] > distance[u.first][u.second] +
            1) {
            q.push({u.first - 1, u.second});
            distance[u.first - 1][u.second] = distance[u.first][u.second] + 1;
        }
        if (u.first < A.size() - 1 && A[u.first + 1][u.second] && distance[u.first + 1][u.second] > distance[u.
                first]
            [u.second] + 1) {
            q.push({u.first + 1, u.second});
            distance[u.first + 1][u.second] = distance[u.first][u.second] + 1;
        }
        if (u.second > 0 && A[u.first][u.second - 1] && distance[u.first][u.second - 1] > distance[u.first][u.
                second] + 1) {
            q.push({u.first, u.second - 1});
            distance[u.first][u.second - 1] = distance[u.first][u.second] + 1;
        }
        if (u.second < A[0].size() - 1 && A[u.first][u.second + 1] && distance[u.first][u.second + 1] > distance[
                u.
                first][u.second] + 1) {
            q.push({u.first, u.second + 1});
            distance[u.first][u.second + 1] = distance[u.first][u.second] + 1;
        }

        // for (int i = 0; i < q.size(); ++i) {
        //     pair<int, int> p = q.front();
        //     cout << "(" << p.first << ", " << p.second << ") ";
        //     q.pop();
        //     q.push(p);
        // }
    }
}

int main() {
    int N, M, INF = 1e9;
    cin >> N >> M;


    vector<vector<bool> > A(N, vector<bool>(M, false));
    vector<vector<int> > distance(N, vector<int>(M, INF));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            if (c == '1') {
                A[i][j] = true;
            } else {
                A[i][j] = false;
            }
        }
    }

    bfs(A, distance);

    // print distance
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < M; ++j) {
    //         cout << distance[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    cout << distance[N - 1][M - 1];
}
