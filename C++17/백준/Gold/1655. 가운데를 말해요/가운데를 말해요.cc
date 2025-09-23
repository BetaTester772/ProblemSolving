#include <bits/stdc++.h>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int> > minHeap;
    priority_queue<int> maxHeap;

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int N, a, b;
    cin >> N;

    cin >> a >> b;
    maxHeap.push(min(a, b));
    cout << a << '\n';

    minHeap.push(max(a, b));
    cout << maxHeap.top() << '\n';


    for (int i = 2; i < N; ++i) {
        cin >> a;
        if (a >= minHeap.top()) {
            minHeap.push(a);
        } else {
            maxHeap.push(a);
        }

        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } else if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        cout << maxHeap.top() << '\n';
    }
}
