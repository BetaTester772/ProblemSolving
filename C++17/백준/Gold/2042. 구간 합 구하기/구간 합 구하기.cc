#include <iostream>
#include <vector>
using namespace std;

vector<long long> arr;
vector<long long> segTree;

long long init(long long node, long long st, long long end) {
        if (st == end) return segTree[node] = arr[st];
        long long mid = (st + end) / 2;

        return segTree[node] = init(node * 2, st, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(long long n, long long st, long long end, long long t, long long diff) {
        if (st <= t && t <= end) segTree[n] += diff;
        else return;

        if (st == end) return;

        long long mid = (st + end) / 2;

        update(n * 2, st, mid, t, diff);
        update(n * 2 + 1, mid + 1, end, t, diff);
}

long long sum(long long l, long long r, long long node, long long st, long long end) {
        if (l <= st && end <= r) return segTree[node];
        if (r < st || end < l) return 0;

        long long m = (st + end) / 2;
        return sum(l, r, node * 2, st, m) + sum(l, r, node * 2 + 1, m + 1, end);
}

int main() {
        long long N, M, K, a, b, c, diff, tmp;
        cin >> N >> M >> K;
        for (long long i = 0; i < N; ++i) {
                cin >> tmp;
                arr.push_back(tmp);
        }
        segTree.resize(N * 4);
        init(1, 0, N - 1);

        for (long long i = 0; i < M + K; ++i) {
                cin >> a >> b >> c;
                if (a == 1) {
                        diff = c - arr[b - 1];
                        arr[b - 1] = c;

                        update(1, 0, N - 1, b - 1, diff);
                } else {
                        cout << sum(b - 1, c - 1, 1, 0, N - 1) << endl;
                }
        }
}
