// https://nicotina04.tistory.com/250
#include <bits/stdc++.h>
#define int long long


using namespace std;

vector<int> S;
vector<int> manacher;
int r = -1; // 이전 팰린드롬의 오른쪽 끝 인덱스
int c = -1; // 이전 팰린드롬의 중심점

void solve() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        S.push_back(0);
        int a;
        cin >> a;
        S.push_back(a);
    }
    S.push_back(0);

    manacher.resize(S.size(), 0); // S[i - manacher[i] ... i + manacher[i]]가 팰린드롬임을 의미

    for (int i = 0; i < S.size(); i++) {
        if (i <= r) {
            manacher[i] = min(r - i, manacher[c + (c - i)]); // 초기 반지름의 길이(팰린드롬의 규칙성 이용)
        }

        while (i + manacher[i] + 1 < S.size() && i - manacher[i] - 1 >= 0 &&
               S[i + manacher[i] + 1] == S[i - manacher[i] - 1] // 팰린드롬의 확장(핵심) - i를 중심으로 좌우 대칭
        ) {
            ++manacher[i];
        }

        // 현재 팰린드롬의 오른쪽 끝이 이전 팰린드롬의 오른쪽 끝보다 크면
        if (i + manacher[i] > r) {
            // 이전 팰린드롬의 중심점과 오른쪽 끝을 갱신
            c = i;
            r = i + manacher[i];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    int Q;
    cin >> Q;

    while (Q--) {
        int L, R;
        cin >> L >> R;
        L = (L - 1) * 2 + 1;
        R = (R - 1) * 2 + 1;

        // L과 R 사이에 팰린드롬이 존재하는지 확인
        if (L > R) {
            cout << "0\n";
            continue;
        }
        int mid = (L + R) / 2;
        cout << (manacher[mid] >= (R - L + 1) / 2 ? 1 : 0) << "\n";
    }
}
