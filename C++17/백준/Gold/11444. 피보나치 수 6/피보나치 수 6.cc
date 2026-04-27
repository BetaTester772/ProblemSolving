#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

unordered_map<long long, long long> mem;

long long f(long long n) {
    if (mem.count(n)) return mem[n];

    // f (2n + 1)
    if (n % 2 == 1) {
        n = (n - 1) / 2;
        long long t = ((f(n + 1) * f(n + 1)) % MOD + (f(n) * f(n)) % MOD) % MOD;
        mem[2 * n + 1] = t;
        return t;
    }
    // f (2n)
    else {
        n = n / 2;
        long long t = (f(n) * (((2 * f(n - 1)) % MOD + f(n)) % MOD)) % MOD;
        mem[2 * n] = t;
        return t;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    long long n;
    cin >> n;

    mem[0] = 0;
    mem[1] = 1;

    cout << f(n);
    // cout << endl;
    //
    //
    // for (long long mem1: mem) {
    //     if (mem1 > -1)
    //         cout << mem1 << ' ';
    // }
}
