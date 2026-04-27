#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
vector<bool> is_prime;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    is_prime.assign(N + 1, true);

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    if (primes.empty() || primes[0] > N) {
        cout << 0;
        return 0;
    }
    int result = 0, sum = primes[0];

    int left = 0, right = 0;
    while (left <= right && right < primes.size()) {
        if (sum < N) {
            sum += primes[++right];
        } else if (sum > N) {
            sum -= primes[left++];
        } else {
            result++;
            sum += primes[++right];
        }
    }
    cout << result;
}
