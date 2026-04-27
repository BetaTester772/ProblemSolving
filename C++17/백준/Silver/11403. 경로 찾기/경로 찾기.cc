#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<vector<int> > reach(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> reach[i][j];

    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (reach[i][k] && reach[k][j])
                    reach[i][j] = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << reach[i][j] << (j == N - 1 ? '\n' : ' ');
    }
    return 0;
}
