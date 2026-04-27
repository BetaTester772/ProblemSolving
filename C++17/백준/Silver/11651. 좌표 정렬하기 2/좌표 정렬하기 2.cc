#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    vector<pair<int, int> > A;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        A.push_back({a, b});
    }

    sort(A.begin(), A.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second < b.second)
            return true;
        else {
            if (a.second == b.second)
                return a.first < b.first;
            else
                return false;
        }
    });

    for (auto a: A) {
        cout << a.first << ' ' << a.second << '\n';
    }
}
