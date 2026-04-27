#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    map<int, int> A;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        A[a]++;
    }
    for (auto &a: A) {
        for (int i = 0; i < a.second; ++i) {
            cout << a.first << '\n';
        }
    }
}
