#include <bits/stdc++.h>

using namespace std;

vector<tuple<char, int, string> > answers; //1-based

int main() {
    int N;
    cin >> N;

    int R, C;
    cin >> R >> C; // 1-based

    vector<vector<int> > ans(N + 1, vector<int>(N + 1, 0)); // 행, 열

    for (int i = 1; i <= N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j) {
            char c = s[j];
            if (c == '.')
                ans[i][j + 1] = 0;
            else if (c == '#')
                ans[i][j + 1] = 1;
        }
    }

    for (int i = 1; i < C; ++i) {
        answers.push_back({'L', R, "push"});
    }
    for (int i = C + 1; i <= N; ++i) {
        answers.push_back({'R', R, "push"});
    }
    for (int i = 1; i < R; ++i) {
        answers.push_back({'U', 1, "push"});
    }
    for (int i = R + 1; i <= N; ++i) {
        answers.push_back({'D', 1, "push"});
    }

    for (int i = 2; i <= N; ++i) {
        if (ans[R][i] == 0) {
            answers.push_back({'D', i, "pull"});
        }
    }
    for (int i = R - 1; i >= 1; --i) {
        for (int j = 2; j <= N; ++j) {
            answers.push_back({'R', i, "push"});
        }
        for (int j = 2; j <= N; ++j) {
            if (ans[i][j] == 0) {
                answers.push_back({'U', j, "pull"});
            }
        }
    }
    for (int i = R + 1; i <= N; ++i) {
        for (int j = 2; j <= N; ++j) {
            answers.push_back({'R', i, "push"});
        }
        for (int j = 2; j <= N; ++j) {
            if (ans[i][j] == 0) {
                answers.push_back({'D', j, "pull"});
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (ans[i][1] == 0) {
            answers.push_back({'L', i, "pull"});
        }
    }

    if (answers.size() == 0) {
        cout << "-1";
        return 0;
    }
    cout << answers.size() << "\n";
    for (auto answer: answers) {
        char a = get<0>(answer);
        int b = get<1>(answer);
        string c = get<2>(answer);

        cout << a << " " << b << " " << c << "\n";
    }
}
