#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<ll> w_lanes(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        cin >> w_lanes[i];
    }

    vector<ll> differential_array(N, 0);

    for (int k = 0; k < M; ++k) {
        int u, v;
        ll x;
        cin >> u >> v >> x;

        differential_array[u - 1] += x;
        differential_array[v - 1] -= x;
    }

    ll current_vehicles_on_road = 0;

    for (int i = 0; i < N - 1; ++i) {
        current_vehicles_on_road += differential_array[i];

        ll c = current_vehicles_on_road;
        ll w = w_lanes[i];

        ll q = c / w;
        ll r = c % w;

        ll road_burden = (r * (q + 1) * (q + 1)) + ((w - r) * q * q);

        cout << road_burden << "\n";
    }
}
