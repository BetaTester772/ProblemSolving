#include <bits/stdc++.h>


using namespace std;
using ll = long long;

int N, M, K;
vector<ll> A;
vector<ll> T;
vector<ll> L;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        T[v] = A[tl];
    } else {
        int tm = (tl + tr) / 2;

        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);

        T[v] = (T[2 * v] + T[2 * v + 1]);
    }
}

void updateLazy(int v, int tl, int tr) {
    if (L[v] != 0) {
        T[v] += L[v] * (tr - tl + 1); // 구간의 합에 더하기
        if (tl != tr) {
            // 리프 노드가 아니면 자식 노드에 lazy 값 전달
            L[2 * v] += L[v];
            L[2 * v + 1] += L[v];
        }
        L[v] = 0; // 현재 노드의 lazy 값 초기화
    }
}

void updateRange(int v, int tl, int tr, int l, int r, ll diff) {
    updateLazy(v, tl, tr); // 현재 노드의 lazy 업데이트
    if (r < tl || l > tr) {
        return; // 구간이 현재 노드와 겹치지 않음
    }

    if (l <= tl && tr <= r) {
        T[v] += diff * (tr - tl + 1); // 구간의 합에 더하기
        if (tl != tr) {
            // 리프 노드가 아니면 자식 노드에 lazy 값 전달
            L[2 * v] += diff;
            L[2 * v + 1] += diff;
        }
    } else {
        int tm = (tl + tr) / 2;
        updateRange(2 * v, tl, tm, l, r, diff);
        updateRange(2 * v + 1, tm + 1, tr, l, r, diff);
        T[v] = T[2 * v] + T[2 * v + 1]; // 현재 노드의 값을 갱신
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    updateLazy(v, tl, tr);

    if (l > r) return 0;
    if (l == tl && r == tr) {
        return T[v];
    }
    int tm = (tl + tr) / 2;
    return (query(2 * v, tl, tm, l, min(r, tm)) +
            query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M >> K;

    A.resize(N + 1);

    T.resize(4 * N + 1);
    L.resize(4 * N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    build(1, 1, N);

    for (int i = 0; i < M + K; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            ll b, c, d;
            cin >> b >> c >> d;
            updateRange(1, 1, N, b, c, d);
        } else if (a == 2) {
            ll b, c;
            cin >> b >> c;
            cout << query(1, 1, N, b, c) << '\n';
        }
    }
}
