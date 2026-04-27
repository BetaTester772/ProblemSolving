#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int N;
    cin >> N;

    unordered_map<ll, ll> dict;
    ll cur = pow(2, 62), count = -1;
    for (int i = 0; i < N; ++i) {
        ll a;
        cin >> a;
        dict[a]++;
        if (dict[a] > count) {
            cur = a;
            count = dict[a];
        } else if (dict[a] == count && a < cur) {
            cur = a;
            count = dict[a];
        }
    }

    cout << cur;
}
