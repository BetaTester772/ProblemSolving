#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pair<int, string> > A;
    for (int i = 0; i < N; ++i) {
        int a;
        string b;
        cin >> a >> b;
        A.push_back({a, b});
    }

    stable_sort(A.begin(), A.end(), [](pair<int, string> a, pair<int, string> b) {
        return a.first < b.first;
    });

    for (auto &a: A) {
        cout << a.first << ' ' << a.second << '\n';
    }
}
