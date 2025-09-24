#include <bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define ll long long

using namespace std;

vector<ll> fibV;
set<ll> fib;

void init() {
    ll a = 1, b = 1, c = 1;
    fibV.PB(1);
    while (c < 1000000000000000000LL) {
        fib.insert(c);
        fibV.PB(c);
        c = a+b;
        a = b;
        b = c;
    }
}

pair<ll, ll> findfib(pair<ll, ll> p) {    // first : level, second : number.
    if (fib.count(p.second) == 0) return p;
    for (int i = 4; i<fibV.size(); i++) {
        if (p.second == fibV[i]) {
            p.first++;
            p.second = i;
            return findfib(p);
        }
    }
}

ll concentrate_fibonacci(ll level, ll x) {
    if (x > 86) return -1;
    else {
        if (level == 1) return fibV[x];
        else return concentrate_fibonacci(level-1, fibV[x]);
    }
}

void solve() {
    ll n;
    cin >> n;
    if (n <= 3) cout << n << '\n';
    else if (fib.count(n) == 1) {
        pair<ll, ll> nn = findfib(MP(0, n));
        ll a = nn.first, b = nn.second; // b is non-fibonacci.
        ll dist = b-4, m = 0;
        for (int i = 4; i<=86; i++) {
            if (b > fibV[i]) m++;
        }
        dist -= m;
        if (dist%2 == 0) {
            if (fib.count(b+1) == 1) cout << concentrate_fibonacci(a, b+2) << '\n';
            else cout << concentrate_fibonacci(a, b+1) << '\n';
        } else {
            if (fib.count(b-1) == 1) cout << concentrate_fibonacci(a+1, b-2) << '\n';
            else cout << concentrate_fibonacci(a+1, b-1) << '\n';
        }
    } else {
        ll dist = n-4, m = 0;
        for (int i = 4; i<=86; i++) {
            if (n > fibV[i]) m++;
        }
        dist -= m;
        if (dist%2 == 0) {
            if (fib.count(n+1) == 1) cout << n+2 << '\n';
            else cout << n+1 << '\n';
        } else {
            if (fib.count(n-1) == 1) cout << concentrate_fibonacci(1, n-2) << '\n';
            else cout << concentrate_fibonacci(1, n-1) << '\n';
        }
    }
}

int main() {
    int T;
    init();
    cin >> T;
    while (T--) solve();
    return 0;
}