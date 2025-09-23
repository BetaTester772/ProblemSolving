#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

i64 N, nxt[1000001], psum[1000001];

void do_input() {
    cin >> N;
    i64 S = 0;
    queue<i64> Q;
    for (i64 i = 1; i <= N; i++) {
        char t;
        cin >> t;
        if (t == 'S') Q.push(i), S++;
        psum[i] = S;
    }
    Q.push(N);

    for (i64 i = 0; i < N; i++) {
        if (i == Q.front()) Q.pop();
        nxt[i] = Q.front();
    }
    nxt[N] = N;
}

i64 ceil_div(i64 a, i64 b) {
    return (a + b - 1) / b;
}

i64 do_solve(i64 x) {
    // cout << "do_solve(" << x << ") called\n";
    i64 res = 0, curr = 0;
    while (x > 0 && curr + x <= N) {
        // cout << "curr: " << curr << ", x: " << x << '\n';
        i64 moves = ceil_div(nxt[curr] - curr, x);
        i64 new_c = curr + x * moves;
        if (new_c > N) moves--, new_c -= x;
        if (moves == 0) break;
        res += moves;
        x -= (psum[new_c] - psum[curr]);
        curr = new_c;
    }
    // cout << "res: " << res << '\n';
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    do_input();
    for (i64 k = 1; k <= N; k++) {
        // do_solve(k);
        cout << do_solve(k) << ' ';
    }
    cout << '\n';
}